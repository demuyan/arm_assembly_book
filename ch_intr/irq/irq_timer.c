#include <stdint.h>

/* シリアル関連 */
#define UART0       ((volatile unsigned int*)0x101f1000)
#define UARTFR      0x06
#define UARTFR_TXFF 0x20

/* タイマー関連 */
#define TIMER0         ((volatile unsigned int*)0x101E2000)
#define TIMER1         ((volatile unsigned int*)0x101E2020)
#define TIMER2         ((volatile unsigned int*)0x101E3000)
#define TIMER3         ((volatile unsigned int*)0x101E3020)
#define TIMER_VALUE    0x1 /* 0x04 bytes */
#define TIMER_CONTROL  0x2 /* 0x08 bytes */
#define TIMER_INTCLR   0x3 /* 0x0C bytes */
#define TIMER_MIS      0x5 /* 0x14 bytes */

#define TIMER_EN       0x80
#define TIMER_PERIODIC 0x40
#define TIMER_INTEN    0x20
#define TIMER_32BIT    0x02
#define TIMER_ONESHOT  0x01

/* PIC(Primary Interrupt Controller)関連 */
#define PIC           ((volatile unsigned int*)0x10140000)
#define PIC_TIMER01   0x10
#define VIC_INTENABLE 0x4 /* 0x10 bytes */

/////begin ch_intr_c_2
/*
 * シリアルへ出力する
 */
void uart_puts(char *s) {
  while(*s) {
    while(*(UART0 + UARTFR) & UARTFR_TXFF);
    *UART0 = *s;
    s++;
  }
}

/*
 * 割り込み(IRQ)発生時
 */
void c_irq_handler() {            
  if(*(TIMER0 + TIMER_MIS)) {             /////-----(f)                             
    /* 文字列をシリアルに出力する */
    uart_puts("timer0 interrupt!\n");     /////-----(g)                        
    /* 割り込みをクリアーする */ 
    *(TIMER0 + TIMER_INTCLR) = 1;         /////-----(h)                        
  }
}
/////end
/////begin ch_intr_c_1
/*
 * 処理関数
 */
void boot_main(void) {

  /* PIC(Primary Interrupt Controller)にてTimer0, Timer1割り込みを許可する */
  *(PIC + VIC_INTENABLE) = PIC_TIMER01; /////-----(8)

  /* Timer0割り込み発生周期設定 */
  *TIMER0 = 1000000;                   /////-----(9)

  /* Timer0割り込み設定 */
  *(TIMER0 + TIMER_CONTROL) =          /////-----(10)
    TIMER_EN | TIMER_PERIODIC | TIMER_32BIT | TIMER_INTEN;

  /* IRQ許可 */
  enable_irq();                        /////-----(11)

  for(;;);                             /////-----(12)
}
/////end

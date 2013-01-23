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

/* PIC(Programable Interrupt Controller)関連 */
#define PIC           ((volatile unsigned int*)0x10140000)
#define PIC_TIMER01   0x10
#define VIC_INTENABLE 0x4 /* 0x10 bytes */

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
 * 割り込み(IRQ)で処理される
 */
void __attribute__((interrupt)) irq_handler() {

  if(*(TIMER0 + TIMER_MIS)) { 
    uart_puts("timer0\n");
    *(TIMER0 + TIMER_INTCLR) = 1; /* 割り込みをクリアーする */
  }

}

/*
 * メイン関数
 */
void main(void) {

  /* PIC(Programable Interrupt Controller)にてTimer0, Timer1割り込みを許可する */
  *(PIC + VIC_INTENABLE) = PIC_TIMER01;

  /* Timer0割り込み発生周期設定 */
  *TIMER0 = 1000000;

  /* Timer0割り込み設定 */
  *(TIMER0 + TIMER_CONTROL) = 
    TIMER_EN | TIMER_PERIODIC | TIMER_32BIT | TIMER_INTEN;

  /* IRQ許可 */
  enable_irq();

  for(;;);
}

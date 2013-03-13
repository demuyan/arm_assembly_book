/////begin ch_intr_swi_c
#include <stdint.h>

/* シリアル関連 */
#define UART0       ((volatile unsigned int*)0x101f1000)
#define UARTFR      0x06
#define UARTFR_TXFF 0x20

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
 * プロセッサモードをシリアルへ出力する
 */
void output_mode()
{
  char buf[3] = "00\n";
  uint32_t val = get_processor_mode();
  buf[0] += val / 0x10;
  buf[1] += val % 0x10;
  uart_puts(" mode=");
  uart_puts(buf);
}
/*
 * ソフトウェア割り込み(SWI)発生時
 */
void c_swi_handler(unsigned char swi_no, uint32_t swi_no2) {  //-----(4)          
  uart_puts("swi");
  output_mode();
}
/*
 * 処理関数
 */
void boot_main(void) { 
  uint32_t i =0;
  for(;;){                    //-----(1)ここから
    i++;
    if (i > 0xf000000){
      uart_puts("boot_main");
      output_mode();          //-----(2)
      call_swi();             //-----(3)
      i=0;
    }
  }                           //-----(1)ここまで
}
/////end

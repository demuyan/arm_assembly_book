#include <stdint.h>

typedef volatile struct {
 uint32_t DR;
 uint32_t RSR_ECR;
 uint8_t reserved1[0x10];
 const uint32_t FR;
 uint8_t reserved2[0x4];
 uint32_t LPR;
 uint32_t IBRD;
 uint32_t FBRD;
 uint32_t LCR_H;
 uint32_t CR;
 uint32_t IFLS;
 uint32_t IMSC;
 const uint32_t RIS;
 const uint32_t MIS;
 uint32_t ICR;
 uint32_t DMACR;
} pl011_T;

enum {
 RXFE = 0x10,
 TXFF = 0x20,
};

pl011_T * const UART0 = (pl011_T *)0x101f1000;
pl011_T * const UART1 = (pl011_T *)0x101f2000;
pl011_T * const UART2 = (pl011_T *)0x101f3000;

static inline char upperchar(char c) {
 if((c >= 'A') && (c <= 'Z')) {
  return c - 'A' + 'a';
 } else {
  return c;
 }
}

static void uart_echo(pl011_T *uart0, pl011_T *uart1) {
 if ((uart0->FR & RXFE) == 0) {
  while(uart0->FR & TXFF);
  uart0->DR = upperchar(uart0->DR);
  uart1->DR = upperchar(uart0->DR);
 }
}

void c_entry() {
 for(;;) {
  uart_echo(UART0, UART1);
//  uart_echo(UART1);
//  uart_echo(UART2);
 }
}

#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_move_1
void arm_move_1() {
  uint32_t d;
  __asm__ (
    "MOV r0,#1    \n\t" // r0レジスタ ← 1
    "MOV %[Rd],r0 \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0");
  printf("r0 = 0x%08x\n",d);
}
/////end

/////begin ch_detail_move_2
void arm_move_2() {
  uint32_t d;
  __asm__ (
    "MVN r0,#1    \n\t" // r0レジスタ ← １をビット反転
    "MOV %[Rd],r0 \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0");
  printf("r0 = 0x%08x\n",d);
}
/////end

int main(int argc, char *argv[]) {
  uint32_t val;

  WRAP("ch_detail_move_1_a", arm_move_1);
  WRAP("ch_detail_move_2_a", arm_move_2);
  return 0;
}

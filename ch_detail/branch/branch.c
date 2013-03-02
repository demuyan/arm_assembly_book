#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_b_1
/*
 * 無条件分岐命令
 */
void arm_b_sample_1() {
  uint32_t d;
  __asm__ (
    "        MOV  r0,#2    \n\t" 
    "        B    finish1  \n\t"
    "        MOV  r0,#10   \n\t"
    "finish1: MOV %[Rd],r2 \n\t"
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_b_2
/*
 * 分岐命令（条件設定あり）
 */
void arm_b_sample_2() {
  uint32_t d;
  __asm__ (
    "        MOV  r0,#2   \n\t" 
    "        MOV  r1,#1   \n\t" 
    "        CMP  r0,r1   \n\t" 
    "        BEQ  next    \n\t" 
    "        MOV  r2,#0   \n\t"
    "        B    finish  \n\t"
    "next:                \n\t"
    "        MOV r2,#1    \n\t"
    "finish: MOV %[Rd],r2 \n\t"

    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2","r3");
  printf("r2 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_bl_1
/*
 * リンク付き分岐命令
 */
void arm_bl_sample_1() {
  uint32_t d;
  __asm__ (
    "        MOV  r0,#2    \n\t" 
    "        BL   subr1    \n\t"
    "        B    finish2  \n\t"
    "subr1:                \n\t"
    "        MOV  r0,#10   \n\t"
    "        BX   lr       \n\t"
    "finish2: MOV %[Rd],r0 \n\t"
    : [Rd] "=r" (d)
    : 
    : "r0", "r14");
  printf("r0 = 0x%08X\n",d);
}
/////end


int main() {

  WRAP("ch_detail_b_1_a",arm_b_sample_1);
  WRAP("ch_detail_b_2_a",arm_b_sample_2);
  WRAP("ch_detail_bl_1_a",arm_bl_sample_1);

  return 0;
}

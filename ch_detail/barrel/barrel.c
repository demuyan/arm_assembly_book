#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_barrel_1
/*
 * バレルシフタ未使用
 */
void arm_barrel_sample_1() {
  uint32_t rd1;
  __asm__ (
    "MOV  r0,#1         \n\t" // r0 ← 1
    "MOV  r1,#2         \n\t" // r1 ← 2
    "LSL  r1,r1,#1      \n\t" // r1 ← r1 LSL 1
    "ADD  r2,r0,r1      \n\t" // r2 ← r0 + r1
    "MOV  %[Rd1],r2     \n\t" // 変数rd1 ← r2
    : [Rd1] "=r" (rd1)
    : 
    : "r0","r1","r2");
  printf("rd1 = %d\n",rd1);
}
/////end

/////begin ch_detail_barrel_2
/*
 * バレルシフタ使用
 */
void arm_barrel_sample_2() {
  uint32_t rd1;
  __asm__ (
    "MOV  r0, #1             \n\t" // r0 ← 1
    "MOV  r1, #2             \n\t" // r1 ← 2
    "ADD  r2, r0, r1, LSL #1 \n\t" // r2 ← r0 + (r1 LSL 1)
    "MOV  %[Rd1],r2          \n\t" // 変数rd1 ← r2
    : [Rd1] "=r" (rd1)
    : 
    : "r0","r1","r2");
  printf("rd1 = %d\n",rd1);
}
/////end

int main() {

  WRAP("ch_detail_barrel_1_a",arm_barrel_sample_1);
  WRAP("ch_detail_barrel_2_a",arm_barrel_sample_2);
  return 0;

}

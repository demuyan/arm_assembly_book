#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/*
 * AND命令 
 */
void arm_and_sample_1() {
  uint32_t d;
  __asm__ (
    "MOV r0,#5     \n\t" // r0 ← 5
    "MOV r1,#3     \n\t" // r1 ← 3
    "AND r0, r0,r1 \n\t" // r0 ← r0 AND r1
    "MOV %[Rd],r0  \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",d);
}

/*
 * ORR命令 
 */
void arm_orr_sample_1() {
  uint32_t d;
  __asm__ (
    "MOV r0,#5     \n\t" // r0 ← 5
    "MOV r1,#3     \n\t" // r1 ← 3
    "ORR r0, r0,r1 \n\t" // r0 ← r0 OR r1
    "MOV %[Rd],r0  \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0","r1");
  printf("r0 = 0x%08X\n",d);
}

/*
 * EOR命令 
 */
void arm_eor_sample_1() {
  uint32_t d;
  __asm__ (
    "MOV r0,#5     \n\t" // r0 ← 5
    "MOV r1,#3     \n\t" // r1 ← 3
    "EOR r0, r0,r1 \n\t" // r0 ← r0 EOR r1
    "MOV %[Rd],r0  \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0","r1");
  printf("r0 = 0x%08X\n",d);
}

/*
 * BIC命令 
 */
void arm_bic_sample_1() {
  uint32_t d;
  __asm__ (
    "MOV r0,#5     \n\t" // r0 ← 5
    "MOV r1,#3     \n\t" // r1 ← 3
    "BIC r0, r0,r1 \n\t" // r0 ← r0 BIC r1
    "MOV %[Rd],r0  \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0","r1");
  printf("r0 = 0x%08X\n",d);
}


int main() {

  WRAP("ch_detail_and_1_a", arm_and_sample_1);
  WRAP("ch_detail_orr_1_a",arm_orr_sample_1);
  WRAP("ch_detail_eor_1_a",arm_eor_sample_1);
  WRAP("ch_detail_bic_1_a",arm_bic_sample_1);

  return 0;
}

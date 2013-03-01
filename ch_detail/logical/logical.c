#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_and_1
/*
 * AND命令 
 */
void arm_and_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "AND  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_orr_1
/*
 * ORR命令 
 */
void arm_orr_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "ORR  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_eor_1
/*
 * EOR命令 
 */
void arm_eor_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "EOR  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_bic_1
/*
 * BIC命令 
 */
void arm_bic_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "BIC  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",d);
}
/////end

int main() {

  WRAP("ch_detail_and_1_a", arm_and_sample_1);
  WRAP("ch_detail_orr_1_a",arm_orr_sample_1);
  WRAP("ch_detail_eor_1_a",arm_eor_sample_1);
  WRAP("ch_detail_bic_1_a",arm_bic_sample_1);

  return 0;
}

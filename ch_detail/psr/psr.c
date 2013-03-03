#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_mrs_1
/*
 * MRS命令
 */
void arm_mrs_sample_1() {
  uint32_t cpsr1;
  __asm__ (
    "MRS  r0, cpsr      \n\t" 
    "MOV  %[CPSR1],r0     \n\t" 
    : [CPSR1] "=r" (cpsr1)
    : 
    : "r0");
  printf("cpsr = 0x%08X\n",cpsr1);
}
/////end

/////begin ch_detail_msr_1
/*
 * MSR命令
 */
void arm_msr_sample_1() {
  uint32_t cpsr1;
  __asm__ (
    "MSR  cpsr_f, #00      \n\t" 
    "MRS  %[CPSR1],cpsr    \n\t" 
    : [CPSR1] "=r" (cpsr1)
    : 
    : "r0");
  printf("cpsr = 0x%08X\n",cpsr1);
}
/////end


/////begin ch_detail_msr_2
/*
 * MSR命令
 */
void arm_msr_sample_2() {
  uint32_t cpsr1,cpsr2,cpsr3;
  __asm__ (
    "MRS r0,cpsr           \n\t"  // キャリーフラグをリセット
    "BIC r0,r0,#0x20000000 \n\t"
    "MSR cpsr_f,r0         \n\t"
    "MRS  %[CPSR1],cpsr    \n\t" 
    ""
    "MRS r0,cpsr           \n\t"  // キャリーフラグをセット
    "ORR r0,r0,#0x20000000 \n\t"
    "MSR cpsr_f,r0         \n\t"
    "MRS  %[CPSR2],cpsr    \n\t" 
    : [CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2)
    : 
    : "r0");
  printf("cpsr1 = 0x%08X\n",cpsr1);
  printf("cpsr2 = 0x%08X\n",cpsr2);
}
/////end


int main() {

  WRAP("ch_detail_mrs_1_a",arm_mrs_sample_1);
  WRAP("ch_detail_msr_1_a",arm_msr_sample_1);
  WRAP("ch_detail_msr_2_a",arm_msr_sample_2);
  return 0;

}

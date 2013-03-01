#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_cmp_1
/*
 * CMP命令 
 */
void arm_cmp_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MRS  %[CPSR1],cpsr\n\t"
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#2     \n\t" 
    "CMP  r0,r1  \n\t" 
    "MRS  %[CPSR2],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2) 
    : 
    : "r0","r1","r2","r3");
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
}
/////end
/////begin ch_detail_cmn_1
/*
 * CMN命令 
 */
void arm_cmn_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MRS  %[CPSR1],cpsr\n\t"
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#-1     \n\t" 
    "CMN  r0,r1  \n\t" 
    "MRS  %[CPSR2],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2) 
    : 
    : "r0","r1","r2","r3");
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
}
/////end
/////begin ch_detail_tst_1
/*
 * TST命令 
 */
void arm_tst_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MRS  %[CPSR1],cpsr\n\t"
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#1     \n\t" 
    "TST  r0,r1  \n\t" 
    "MRS  %[CPSR2],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2) 
    : 
    : "r0","r1","r2","r3");
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
}
/////end
/////begin ch_detail_teq_1
/*
 * TST命令 
 */
void arm_teq_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MRS  %[CPSR1],cpsr\n\t"
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#1     \n\t" 
    "TEQ  r0,r1  \n\t" 
    "MRS  %[CPSR2],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2) 
    : 
    : "r0","r1","r2","r3");
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
}
/////end


int main() {

  WRAP("ch_detail_cmp_1_a",arm_cmp_sample_1);
  WRAP("ch_detail_cmn_1_a",arm_cmn_sample_1);

  WRAP("ch_detail_tst_1_a",arm_tst_sample_1);
  WRAP("ch_detail_teq_1_a",arm_teq_sample_1);

  return 0;
}

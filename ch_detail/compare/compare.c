#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../wrap.h"

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

/////begin ch_detail_cmp_1
/*
 * CMP命令 
 */
void arm_cmp_sample_1() {
  uint32_t cpsr1;
  __asm__ (
    "MSR cpsr_f,#0     \n\t" // フラグをクリア
    ""    
    "MOV r0,#1         \n\t" // r0 ← 1
    "MOV r1,#2         \n\t" // r1 ← 2
    "CMP r0,r1         \n\t" // cpsr ← r0 - r1
    "MRS %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1)
    : 
    : "r0","r1");
  printf("flag1 = %s\n", byte_to_binary(cpsr1 >> 24));
}
/////end
/////begin ch_detail_cmn_1
/*
 * CMN命令 
 */
void arm_cmn_sample_1() {
  uint32_t cpsr1;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // フラグをクリア

    "MOV  r0,#1         \n\t" // r0 ← 5
    "MOV  r1,#-1        \n\t" // r1 ← -1
    "CMN  r0,r1         \n\t" // cpsr ← r0+r1
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1)
    : 
    : "r0","r1");
  printf("flag1 = %s\n", byte_to_binary(cpsr1 >> 24));
}
/////end
/////begin ch_detail_tst_1
/*
 * TST命令 
 */
void arm_tst_sample_1() {
  uint32_t cpsr1;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // フラグをクリア
    ""    
    "MOV  r0,#1         \n\t" // r0 ← 1
    "MOV  r1,#1         \n\t" // r1 ← 1
    "TST  r0,r1         \n\t" // cpsr ← (r0 AND r1)
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1)
    : 
    : "r0","r1");
  printf("flag1 = %s\n", byte_to_binary(cpsr1 >> 24));
}
/////end
/////begin ch_detail_teq_1
/*
 * TEQ命令 
 */
void arm_teq_sample_1() {
  uint32_t cpsr1;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // フラグをクリア
    "MOV  r0,#1         \n\t" // r0 ← 1
    "MOV  r1,#1         \n\t" // r1 ← 1
    "TEQ  r0,r1         \n\t" // cpsr ← r0 EOR r1
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1)
    : 
    : "r0","r1","r2","r3");
  printf("flag1 = %s\n", byte_to_binary(cpsr1 >> 24));
}
/////end


int main() {

  WRAP("ch_detail_cmp_1_a",arm_cmp_sample_1);
  WRAP("ch_detail_cmn_1_a",arm_cmn_sample_1);

  WRAP("ch_detail_tst_1_a",arm_tst_sample_1);
  WRAP("ch_detail_teq_1_a",arm_teq_sample_1);

  return 0;
}

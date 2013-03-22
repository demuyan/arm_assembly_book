#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../wrap.h"

const char *display_flags(int x)
{
    static char b[256];
    b[0] = '\0';

    strcat(b, "n=");
    strcat(b, (x & 0x80)? "1":"0");
    strcat(b, " z=");
    strcat(b, (x & 0x40)? "1":"0");
    strcat(b, " c=");
    strcat(b, (x & 0x20)? "1":"0");
    strcat(b, " v=");
    strcat(b, (x & 0x10)? "1":"0");

    return b;
}

/*
 * CMP命令 
 */
/////begin ch_detail_cmp_1
void arm_cmp_sample_1() {
  uint32_t cpsr1,cpsr2;
  __asm__ (
    "MSR cpsr_f,#0     \n\t" // cpsrのフラグフィールドをクリア
    "LDR r0,=1         \n\t" // r0 ← 1
    "LDR r1,=2         \n\t" // r1 ← 2
    "CMP r0,r1         \n\t" // cpsr ← (r0 - r1)の結果
    "MRS %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    "LDR r0,=10        \n\t" // r0 ← 10
    "LDR r1,=10        \n\t" // r1 ← 10
    "CMP r0,r1         \n\t" // cpsr ← (r0 - r1)の結果
    "MRS %[CPSR2],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2)
    : 
    : "r0","r1");
  printf("flag1 : %s\n", display_flags(cpsr1 >> 24));
  printf("flag2 : %s\n", display_flags(cpsr2 >> 24)); 
}
/////end
/*
 * CMN命令 
 */
/////begin ch_detail_cmn_1
void arm_cmn_sample_1() {
  uint32_t cpsr1,cpsr2;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // cpsrのフラグフィールドをクリア
    "MOV  r0,#1         \n\t" // r0 ← 1
    "MOV  r1,#-1        \n\t" // r1 ← -1
    "CMN  r0,r1         \n\t" // cpsr ← (r0 + r1)の結果
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    "MOV  r0,#10        \n\t" // r0 ← 10
    "MOV  r1,#10        \n\t" // r1 ← 10
    "CMN  r0,r1         \n\t" // cpsr ← (r0 + r1)の結果
    "MRS  %[CPSR2],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2)
    : 
    : "r0","r1");
  printf("flag1 : %s\n", display_flags(cpsr1 >> 24));
  printf("flag2 : %s\n", display_flags(cpsr2 >> 24)); 
}
/////end
/*
 * TST命令 
 */
/////begin ch_detail_tst_1
void arm_tst_sample_1() {
  uint32_t cpsr1,cpsr2;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // cpsrのフラグフィールドをクリア
    "LDR  r0,=0x01      \n\t" // r0 ← 0x01
    "LDR  r1,=0x02      \n\t" // r1 ← 0x02
    "TST  r0,r1         \n\t" // cpsr ← (r0 AND r1)の結果
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    "LDR  r0,=0x01      \n\t" // r0 ← 0x01
    "LDR  r1,=0x01      \n\t" // r1 ← 0x01
    "TST  r0,r1         \n\t" // cpsr ← (r0 AND r1)の結果
    "MRS  %[CPSR2],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2)
    : 
    : "r0","r1");
  printf("flag1 : %s\n", display_flags(cpsr1 >> 24));
  printf("flag2 : %s\n", display_flags(cpsr2 >> 24)); 
}
/////end
/*
 * TEQ命令 
 */
/////begin ch_detail_teq_1
void arm_teq_sample_1() {
  uint32_t cpsr1,cpsr2;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // cpsrのフラグフィールドをクリア
    "LDR  r0,=0x01      \n\t" // r0 ← 0x01
    "LDR  r1,=0x01      \n\t" // r1 ← 0x01
    "TEQ  r0,r1         \n\t" // cpsr ← (r0 EOR r1)の結果
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr
    "LDR  r0,=0x01      \n\t" // r0 ← 0x01
    "LDR  r1,=0x03      \n\t" // r1 ← 0x03
    "TEQ  r0,r1         \n\t" // cpsr ← (r0 EOR r1)の結果
    "MRS  %[CPSR2],cpsr \n\t" // 変数cpsr1 ← cpsr
    : [CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2)
    : 
    : "r0","r1","r2","r3");
  printf("flag1 : %s\n", display_flags(cpsr1 >> 24));
  printf("flag2 : %s\n", display_flags(cpsr2 >> 24)); 
}
/////end


int main() {

  WRAP("ch_detail_cmp_1_a",arm_cmp_sample_1);
  WRAP("ch_detail_cmn_1_a",arm_cmn_sample_1);

  WRAP("ch_detail_tst_1_a",arm_tst_sample_1);
  WRAP("ch_detail_teq_1_a",arm_teq_sample_1);

  return 0;
}

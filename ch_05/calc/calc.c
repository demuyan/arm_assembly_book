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
 * ADD命令
 */
void arm_add_sample_1() {
  uint32_t rd1,rd2,cpsr1,cpsr2;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // cpsrのフラグフィールドをクリア
    "LDR  r0,=1         \n\t" // r0 ← 1
    "LDR  r1,=-1        \n\t" // r0 ← -1
    "ADD  r2,r0,r1      \n\t" // r2=r0+r1
    "MOV  %[Rd1],r2     \n\t" // 変数rd1 ← r2
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr

    "LDR  r0,=1         \n\t" // r0 ← 1
    "LDR  r1,=2         \n\t" // r1 ← 2
    "ADD  r3,r0,r1      \n\t" // r3=r0+r1
    "MOV  %[Rd2],r3     \n\t" // 変数rd2 ← r3
    "MRS  %[CPSR2],cpsr \n\t" // 変数cpsr2 ← cpsr
    : [Rd1] "=r" (rd1) ,[Rd2] "=r" (rd2),[CPSR1] "=r" (cpsr1), [CPSR2] "=r" (cpsr2)
    : 
    : "r0","r1","r2","r3");
  printf("rd1 = %d\n",rd1);
  printf("rd2 = %d\n",rd2);
  printf("flag1 : %s\n", display_flags(cpsr1 >> 24));
  printf("flag2 : %s\n", display_flags(cpsr2 >> 24)); 
}

/*
 * ADD命令
 */
void arm_add_sample_2() {
  uint32_t rd1,rd2,cpsr1,cpsr2;
  __asm__ (
    "MSR  cpsr_f,#0     \n\t" // cpsrのフラグフィールドをクリア
    "LDR  r0,=1         \n\t" // r0 ← 1
    "LDR  r1,=-1        \n\t" // r1 ← -1
    "ADDS r2,r0,r1      \n\t" // r2=r0+r1(結果をcpsrに反映)
    "MOV  %[Rd1],r2     \n\t" // 変数rd1 ← r2
    "MRS  %[CPSR1],cpsr \n\t" // 変数cpsr1 ← cpsr

    "LDR  r0,=1         \n\t" // r0 ← 1
    "LDR  r1,=2         \n\t" // r1 ← 2
    "ADDS r3,r0,r1      \n\t" // r3=r0+r1
    "MOV  %[Rd2],r3     \n\t" // 変数rd2 ← r3
    "MRS  %[CPSR2],cpsr \n\t" // 変数cpsr2 ← cpsr
    : [Rd1] "=r" (rd1) ,[Rd2] "=r" (rd2),[CPSR1] "=r" (cpsr1), [CPSR2] "=r" (cpsr2)
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",rd1);
  printf("r3 = %d\n",rd2);
  printf("flag1 : %s\n", display_flags(cpsr1 >> 24));
  printf("flag2 : %s\n", display_flags(cpsr2 >> 24)); 
}

/*
 * ADC命令
 */
void arm_adc_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MRS r0,cpsr           \n\t" // r0 ← cpsr
    "ORR r0,r0,#0x20000000 \n\t" // r0 ← (r0 | 0x20000000) つまりキャリーフラグのセット
    "MSR cpsr_f,r0         \n\t" // cpsrのフラグフィールド ← r0
    "MRS %[CPSR],cpsr      \n\t" // 変数cpsr ← cpsr

    "LDR r0,=1             \n\t" // r0 ← 1
    "LDR r1,=2             \n\t" // r1 ← 2
    "ADC r2,r0,r1          \n\t" // r2 ← r0 + r1 + キャリーフラグ
    "MOV %[Rd],r2          \n\t" // 変数rd2 ← r2
    : [Rd] "=r" (d),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("flag : %s\n", display_flags(cpsr >> 24));
}

/*
 * ADC命令
 * (r5,r4) = (r1,r0) + (r3,r2)
 */
void arm_adc_sample_2() {
  uint32_t rd1,rd2,cpsr;

  /* 64ビット値[r5,r4] = 64ビット値[r1,r0] + 64ビット値[r3,r2]  */
  __asm__ (
    /* 1つ目の64ビット値 */
    "LDR  r0,=0x80000002  \n\t" // r0 ← 0x80000002 下位32ビット 
    "LDR  r1,=0x00000000  \n\t" // r1 ← 0x00000000 上位32ビット 

    /* 2つ目の64ビット値 */
    "LDR  r2,=0x80000001  \n\t" // r2 ← 0x80000001 下位32ビット 
    "LDR  r3,=0x00000000  \n\t" // r3 ← 0x00000000 上位32ビット 

    "ADDS r4,r2,r0        \n\t" // r4 ← r2 + r0  (演算結果はcpsrに反映) 下位32ビットを演算
    "ADC  r5,r1,r3        \n\t" // r5 ← r1 + r3 + キャリーフラグ        上位32ビットを演算
    "MOV  %[Rd1],r4       \n\t" // 変数rd1 ← r4
    "MOV  %[Rd2],r5       \n\t" // 変数rd2 ← r5
    "MRS  %[CPSR],cpsr    \n\t" // 変数cpsr ← cpsr
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3","r4","r5");
  printf("r4 = 0x%08X\n",rd1); // 演算結果　下位32ビット
  printf("r5 = 0x%08X\n",rd2); // 演算結果　上位32ビット
  printf("flag : %s\n", display_flags(cpsr >> 24));
}

/*
 * SUB命令
 */
void  arm_sub_sample_1() {
  uint32_t d;
  __asm__ (
    "LDR  r0,=5        \n\t" // r0 ← 5
    "LDR  r1,=1        \n\t" // r1 ← 1
    "SUB  r2,r0,r1     \n\t" // r2 ← r0 - r1
    "MOV  %[Rd],r2     \n\t" // 変数rd ← r2
    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2");
  printf("r2 = %d\n",d);
}

/*
 * SBC命令
 */
void  arm_sbc_sample_1() {
  uint32_t rd1,rd2,cpsr;

  /* 64ビット値[r5,r4] = 64ビット値[r1,r0] - 64ビット値[r3,r2]  */
  __asm__ (
    /* 1つ目の64ビット値 */
    "LDR  r0,=0x10     \n\t" // r0 ← 0x10  下位32ビット 
    "LDR  r1,=0x20     \n\t" // r1 ← 0x20  上位32ビット

    /* 2つ目の64ビット値 */
    "LDR  r2,=0x20     \n\t" // r2 ← 0x20  下位32ビット 
    "LDR  r3,=0x10     \n\t" // r3 ← 0x10  上位32ビット

    "SUBS r4,r0,r2     \n\t" // r4 ← r0 - r2 (演算結果はcpsrに反映)  下位32ビットを演算
    "SBC  r5,r1,r3     \n\t" // r5 ← r1 - r3 - NOT(キャリーフラグ)   上位32ビットを演算
    "MOV  %[Rd1],r4    \n\t" // 変数rd1 ← r4
    "MOV  %[Rd2],r5    \n\t" // 変数rd2 ← r5
    "MRS  %[CPSR],cpsr \n\t" // 変数cpsr ← cpsr
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3","r4","r5");
  printf("r4 = 0x%08X\n",rd1); // 演算結果　下位32ビット
  printf("r5 = 0x%08X\n",rd2); // 演算結果　上位32ビット
  printf("flag : %s\n", display_flags(cpsr >> 24));
}

/*
 * RSB命令
 */
void arm_rsb_sample_1() {
  uint32_t d;
  __asm__ (
    "LDR  r0,=5        \n\t" // r0 ← 5
    "RSB  r2,r0,#0     \n\t" // r2 ← 0 - r0
    "MOV  %[Rd],r2     \n\t" // 変数rd   ← r2
    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
}

/*
 * RSC命令
 */
void arm_rsc_sample_1() {
  uint32_t rd1,rd2,cpsr;

  /* 64ビット値[r5,r4] = 0 - 64ビット値[r1,r0]  */
  __asm__ (

    "LDR  r0,=0x10     \n\t" // r0 ← 0x10 下位32ビット
    "LDR  r1,=0x20     \n\t" // r1 ← 0x20 上位32ビット

    "RSBS r4,r0,#0     \n\t" // r4 ← 0 - r0 (演算結果はcpsrに反映) 下位32ビットを演算
    "RSC  r5,r1,#0     \n\t" // r5 ← 0 - r1 - NOT(キャリーフラグ)  上位32ビットを演算
    "MOV  %[Rd1],r4    \n\t" // 変数rd1  ← r4
    "MOV  %[Rd2],r5    \n\t" // 変数rd2  ← r5
    "MRS  %[CPSR],cpsr \n\t" // 変数cpsr ← cpsr
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3","r4","r5");
  printf("r4 = 0x%08X\n",rd1); // 演算結果　下位32ビット
  printf("r5 = 0x%08X\n",rd2); // 演算結果　上位32ビット
  printf("flag : %s\n", display_flags(cpsr >> 24));
}

/*
 * MUL命令
 */
void arm_mul_sample_1() {
  uint32_t d;
  __asm__ (
    "LDR  r0,=5         \n\t" // r0 ← 5
    "LDR  r1,=2         \n\t" // r1 ← 2
    "MUL  r2,r0,r1      \n\t" // r2 ← r0 * r1
    "MOV  %[Rd],r2      \n\t" // 変数rd ← r2
    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2");
  printf("r2 = %d\n",d);
}

/*
 * UMULL命令
 */
void arm_umull_sample_1() {
  uint32_t rd1,rd2;
  __asm__ (
    "LDR   r0,=0x80000000  \n\t" // r0 ← 0x80000000
    "LDR   r1,=0x00000003  \n\t" // r1 ← 0x00000003
    "UMULL r2,r3,r0,r1     \n\t" // (r3,r2) ← 符号無し(r0 * r1)
    "MOV   %[Rd1],r3       \n\t" // 変数rd1 ← r3
    "MOV   %[Rd2],r2       \n\t" // 変数rd2 ← r2
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2","r3");
  printf("r3 = 0x%08X\n",rd1); // 演算結果　上位32ビット
  printf("r2 = 0x%08X\n",rd2); // 演算結果　下位32ビット
}

/*
 * SMULL命令
 */
void arm_smull_sample_1() {
  uint32_t rd1,rd2;
  __asm__ (
    "LDR   r0,=0x80000000  \n\t" // r0 ← 0x80000000
    "LDR   r1,=0x00000003  \n\t" // r1 ← 0x00000003
    "SMULL r2,r3,r0,r1     \n\t" // (r3,r2) ← 符号付き(r0 * r1)
    "MOV   %[Rd1],r3       \n\t" // 変数rd1 ← r3
    "MOV   %[Rd2],r2       \n\t" // 変数rd2 ← r2
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2","r3");
  printf("r3 = 0x%08X\n",rd1); // 演算結果　上位32ビット
  printf("r2 = 0x%08X\n",rd2); // 演算結果　下位32ビット
}

/*
 * MLA命令
 */
void arm_mla_sample_1() {
  uint32_t d;
  __asm__ (
    "LDR  r0,=5        \n\t" // r0 ← 5
    "LDR  r1,=2        \n\t" // r1 ← 2
    "LDR  r2,=2        \n\t" // r2 ← 2
    "MLA  r3,r0,r1,r2  \n\t" // r3 ← r0 * r1 + r2
    "MOV  %[Rd],r3     \n\t" // 変数rd ← r3
    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2","r3");
  printf("r3 = %d\n",d);
}

/*
 * UMLAL命令
 */
void arm_umlal_sample_1() {
  uint32_t rd1,rd2;
  __asm__ (
    "LDR   r0,=0x2         \n\t" // r0 ← 0x2
    "LDR   r1,=0xffffffff  \n\t" // r1 ← 0xffffffff
    "LDR   r2,=0           \n\t" // r2 ← 0
    "LDR   r3,=1           \n\t" // r3 ← 1
    "UMLAL r2,r3, r0,r1    \n\t" // (r3,r2) ← 符号なし(r0 * r1 + (r2,r3))
    "MOV   %[Rd1],r3       \n\t" // 変数rd1 ← r3
    "MOV   %[Rd2],r2       \n\t" // 変数rd2 ← r2
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2","r3");
  printf("r3 = 0x%08X\n",rd1); // 演算結果　上位32ビット
  printf("r2 = 0x%08X\n",rd2); // 演算結果　下位32ビット
}

/*
 * SMLAL命令
 */
void arm_smlal_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "LDR   r0,=0x2        \n\t" // r0 ← 0x2
    "LDR   r1,=-1         \n\t" // r1 ← -1(=0xffffffff)
    "LDR   r2,=0          \n\t" // r2 ← 0 
    "LDR   r3,=1          \n\t" // r3 ← 1
    "SMLAL r2,r3, r0,r1   \n\t" // (r3,r2) ← 符号付き(r0*r1+(r3,r2))
    "MOV   %[Rd1],r3      \n\t" // 変数rd1 ← r3
    "MOV   %[Rd2],r2      \n\t" // 変数rd2 ← r2
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2","r3");
  printf("r3 = 0x%08X\n",rd1); // 演算結果　上位32ビット
  printf("r2 = 0x%08X\n",rd2); // 演算結果　下位32ビット
}

int main() {

  WRAP("ch_detail_add_1_a",arm_add_sample_1);
  WRAP("ch_detail_add_2_a",arm_add_sample_2);
  WRAP("ch_detail_adc_1_a",arm_adc_sample_1);
  WRAP("ch_detail_adc_2_a",arm_adc_sample_2);

  WRAP("ch_detail_sub_1_a",arm_sub_sample_1);
  WRAP("ch_detail_sbc_1_a",arm_sbc_sample_1);
  WRAP("ch_detail_rsb_1_a",arm_rsb_sample_1);
  WRAP("ch_detail_rsc_1_a",arm_rsc_sample_1);

  WRAP("ch_detail_mul_1_a",arm_mul_sample_1);
  WRAP("ch_detail_umull_1_a",arm_umull_sample_1);
  WRAP("ch_detail_smull_1_a",arm_smull_sample_1);

  WRAP("ch_detail_mla_1_a",arm_mla_sample_1);
  WRAP("ch_detail_umlal_1_a",arm_umlal_sample_1);
  WRAP("ch_detail_smlal_1_a",arm_smlal_sample_1);

  return 0;
}

#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_add_1
/*
 * ADD命令
 */
void arm_add_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#2     \n\t" 
    "ADDS r2,r0,r1  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_add_2
/*
 * ADD命令
 */
void arm_add_sample_2() {
  uint32_t d,cpsr;
  __asm__ (
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#-1     \n\t" 
    "ADDS r2,r0,r1  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_adc_1
/*
 * ADC命令
 */
void arm_adc_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MRS r1,cpsr\n\t"
    "BIC r1,r1,#0x20000000\n\t"
    "MSR cpsr_f,r1\n\t"
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#2     \n\t" 
    "ADC  r2,r0,r1  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_adc_2
/*
 * ADC命令
 */
void arm_adc_sample_2() {
  uint32_t d,cpsr;
  __asm__ (
    "MRS r1,cpsr\n\t"
    "ORR r1,r1,#0x20000000\n\t"
    "MSR cpsr_f,r1\n\t"
    "MOV  r0,#1     \n\t" 
    "MOV  r1,#2     \n\t" 
    "ADC  r2,r0,r1  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_adc_3
/*
 * ADC命令
 */
void arm_adc_sample_3() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r0,#0x80000002     \n\t" // (r5,r4) = (r1,r0) + (r3,r2)
    "MOV  r1,#0x00000000     \n\t" 
    "MOV  r2,#0x80000001     \n\t" 
    "MOV  r3,#0x00000000     \n\t" 
    "ADD  r4,r2,r0  \n\t" 
    "ADC  r5,r1,r3  \n\t" 
    "MOV  %[Rd1],r4 \n\t" 
    "MOV  %[Rd2],r5 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3","r4","r5");
  printf("r4 = %08X\n",rd1);
  printf("r5 = %08X\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_sub_1
/*
 * SUB命令
 */
void  arm_sub_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#1     \n\t" 
    "SUB  r2,r0,r1  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_sbc_1
/*
 * SBC命令
 */
void  arm_sbc_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r0,#0x10     \n\t" // (r5,r4) =  (r1,r0) - (r3,r2)  
    "MOV  r1,#0x20     \n\t" 
    "MOV  r2,#0x20     \n\t" 
    "MOV  r3,#0x10     \n\t" 
    "SUBS r4,r0,r2  \n\t" 
    "SBC  r5,r1,r3  \n\t" 
    "MOV  %[Rd1],r4 \n\t" 
    "MOV  %[Rd2],r5 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3","r4","r5");
  printf("r4 = 0x%08X\n",rd1);
  printf("r5 = 0x%08X\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_rsb_1
/*
 * RSB命令
 */
void arm_rsb_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "RSB  r2,r0,#0  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_rsc_1
/*
 * RSC命令
 */
void arm_rsc_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r0,#0x10     \n\t" // (r5,r4) =  (r1,r0) - (r3,r2)  
    "MOV  r1,#0x20     \n\t" 
    "RSBS r4,r0,#0  \n\t" 
    "RSC  r5,r1,#0  \n\t" 
    "MOV  %[Rd1],r4 \n\t" 
    "MOV  %[Rd2],r5 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2),[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3","r4","r5");
  printf("r4 = 0x%08X\n",rd1);
  printf("r5 = 0x%08X\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);

}
/////end
/////begin ch_detail_mul_1
/*
 * MUL命令
 */
void arm_mul_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#2     \n\t" 
    "MUL  r2,r0,r1  \n\t" 
    "MOV  %[Rd],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);

}
/////end
/////begin ch_detail_umull_1
/*
 * UMULL命令
 */
void arm_umull_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r1,#20    \n\t" 
    "MOV  r0,#20    \n\t" 
    "MOV  r1, r1, LSL #15    \n\t" 
    "MOV  r0, r0, LSL #12    \n\t" 
    "UMULLS  r2,r3, r0,r1  \n\t" 
    "MOV  %[Rd1],r3 \n\t" 
    "MOV  %[Rd2],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r3 = %d\n",rd1);
  printf("r2 = %d\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);

}
/////end
/////begin ch_detail_sumll_1
/*
 * SUMLL命令
 */
void arm_sumll_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r1,#20    \n\t" 
    "MOV  r0,#20    \n\t" 
    "MOV  r1, r1, LSL #15    \n\t" 
    "MOV  r0, r0, LSL #12    \n\t" 
    "SMULLS  r2,r3, r0,r1   \n\t" 
    "MOV  %[Rd1],r3 \n\t" 
    "MOV  %[Rd2],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r3 = %d\n",rd1);
  printf("r2 = %d\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end
/////begin ch_detail_mla_1
/*
 * MLA命令
 */
void arm_mla_sample_1() {
  uint32_t d,cpsr;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#2     \n\t" 
    "MOV  r2,#2     \n\t" 
    "MLA  r3,r0,r1,r2  \n\t" 
    "MOV  %[Rd],r3 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd] "=r" (d) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r3 = %d\n",d);
  printf("cpsr = 0x%08X\n",cpsr);

}
/////end
/////begin ch_detail_umlal_1
/*
 * UMLAL命令
 */
void arm_umlal_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r1,#20    \n\t" 
    "MOV  r0,#20    \n\t" 
    "MOV  r2,#0    \n\t" 
    "MOV  r3,#1    \n\t" 
    "MOV  r1, r1, LSL #15    \n\t" 
    "MOV  r0, r0, LSL #12    \n\t" 
    "UMLALS  r2,r3, r0,r1  \n\t" 
    "MOV  %[Rd1],r3 \n\t" 
    "MOV  %[Rd2],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r3 = %d\n",rd1);
  printf("r2 = %d\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);

}
/////end
/////begin ch_detail_smlal_1
/*
 * SMLAL命令
 */
void arm_smlal_sample_1() {
  uint32_t rd1,rd2,cpsr;
  __asm__ (
    "MOV  r1,#20    \n\t" 
    "MOV  r0,#20    \n\t" 
    "MOV  r1, r1, LSL #15    \n\t" 
    "MOV  r0, r0, LSL #12    \n\t" 
    "MOV  r2,#0    \n\t" 
    "MOV  r3,#1    \n\t" 
    "SMLALS  r2,r3, r0,r1   \n\t" 
    "MOV  %[Rd1],r3 \n\t" 
    "MOV  %[Rd2],r2 \n\t" 
    "MRS  %[CPSR],cpsr\n\t"
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[CPSR] "=r" (cpsr) 
    : 
    : "r0","r1","r2","r3");
  printf("r3 = %d\n",rd1);
  printf("r2 = %d\n",rd2);
  printf("cpsr = 0x%08X\n",cpsr);
}
/////end

int main() {
  uint32_t val;

  WRAP("ch_detail_add_1_a",arm_add_sample_1);
  WRAP("ch_detail_add_2_a",arm_add_sample_2);

  WRAP("ch_detail_adc_1_a",arm_adc_sample_1);
  WRAP("ch_detail_adc_2_a",arm_adc_sample_2);
  WRAP("ch_detail_adc_3_a",arm_adc_sample_3);

  WRAP("ch_detail_sub_1_a",arm_sub_sample_1);
  WRAP("ch_detail_sbc_1_a",arm_sbc_sample_1);
  WRAP("ch_detail_rsb_1_a",arm_rsb_sample_1);
  WRAP("ch_detail_rsc_1_a",arm_rsc_sample_1);

  WRAP("ch_detail_mul_1_a",arm_mul_sample_1);
  WRAP("ch_detail_umull_1_a",arm_umull_sample_1);
  WRAP("ch_detail_sumll_1_a",arm_sumll_sample_1);

  WRAP("ch_detail_mla_1_a",arm_mla_sample_1);
  WRAP("ch_detail_umlal_1_a",arm_umlal_sample_1);
  WRAP("ch_detail_smlal_1_a",arm_smlal_sample_1);

  return 0;
}

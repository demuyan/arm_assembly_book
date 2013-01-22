#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_cmp_sample_1() {
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
  printf("func: %s\n",__func__);
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmn_sample_1() {
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
  printf("func: %s\n",__func__);
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_sample_1() {
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
  printf("func: %s\n",__func__);
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_teq_sample_1() {
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
  printf("func: %s\n",__func__);
  printf("CPSR1 = 0x%08X\n",cpsr1);
  printf("CPSR2 = 0x%08X\n",cpsr2);
  return d;
}


int main() {

  arm_cmp_sample_1();
  arm_cmn_sample_1();

  arm_tst_sample_1();
  arm_teq_sample_1();

  return 0;
}

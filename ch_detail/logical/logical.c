#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_and_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "AND  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("func: %s\n",__func__);
  printf("Rd = 0x%08X\n",d);
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_orr_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "ORR  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("func: %s\n",__func__);
  printf("Rd = 0x%08X\n",d);
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_eor_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "EOR  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("func: %s\n",__func__);
  printf("Rd = 0x%08X\n",d);
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_bic_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "MOV  r0,#5     \n\t" 
    "MOV  r1,#3     \n\t" 
    "BIC  r0, r0,r1  \n\t" 
    "MOV  %[Rd],r0  \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("func: %s\n",__func__);
  printf("Rd = 0x%08X\n",d);
  return d;
}


int main() {

  arm_and_sample_1();
  arm_orr_sample_1();
  arm_eor_sample_1();
  arm_bic_sample_1();

  return 0;
}

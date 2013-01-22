#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_b_sample_1() {
  uint32_t d,cpsr1,cpsr2;
  __asm__ (
    "        MOV  r0,#2     \n\t" 
    "        MOV  r1,#1     \n\t" 
    "        CMP  r0,r1  \n\t" 
    "        BEQ  next \n\t" 
    "        MOV  r2,#0 \n\t"
    "        B    finish \n\t"
    "next:           \n\t"
    "        MOV r2,#1 \n\t"
    "finish: MOV %[Rd],r2\n\t"

    : [Rd] "=r" (d) ,[CPSR1] "=r" (cpsr1),[CPSR2] "=r" (cpsr2) 
    : 
    : "r0","r1","r2","r3");
  printf("func: %s\n",__func__);
  printf("Rd1 = 0x%08X\n",d);
  return d;
}

int main() {

  arm_b_sample_1();


  return 0;
}

#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_sel(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("SEL %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2));
  return d;
}


int main() {
  uint32_t val,val2;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  val2 = 0x00000010;
  printf("val2 = 0x%08X\n", val2);
  printf("arm_sel(val,val2) = 0x%08X\n", arm_sel(val,val2));

  return 0;
}

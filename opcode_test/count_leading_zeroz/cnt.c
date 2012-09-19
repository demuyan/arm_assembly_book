#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_clz(uint32_t v) {
  uint32_t d;
  asm ("CLZ %[Rd], %[Rm]" 
       : [Rd] "+r" (d) 
       : [Rm] "r" (v));
  return d;
}

int main() {
  uint32_t val;

  val = 0x00000001;
  printf("arm_clz(0x%08X) = 0x%08X\n", val,arm_clz(val));
  val = 0x00f0f0f0;
  printf("arm_clz(0x%08X) = 0x%08X\n", val,arm_clz(val));
  val = 0x7fffffff;
  printf("arm_clz(0x%08X) = 0x%08X\n", val,arm_clz(val));

  return 0;
}

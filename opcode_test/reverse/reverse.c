#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t thumb2_rbit(uint32_t v) {
  uint32_t d;
  asm ("RBIT %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rev(uint32_t v) {
  uint32_t d;
  asm ("REV %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rev16(uint32_t v) {
  uint32_t d;
  asm ("REV16 %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_revsh(uint32_t v) {
  uint32_t d;
  asm ("REVSH %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}


int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("thumb2_rbit(val) = 0x%08X\n", thumb2_rbit(val));
  printf("arm_rev(val) = 0x%08X\n", arm_rev(val));
  printf("arm_rev16(val) = 0x%08X\n", arm_rev16(val));
  printf("arm_revsh(val) = 0x%08X\n", arm_revsh(val));

  return 0;
}

#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_sdiv(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "SDIV %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_udiv(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UDIV %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("arm_udiv(val, 2) = 0x%08X\n", arm_udiv(val, 2));
  printf("arm_sdiv(val, 2) = 0x%08X\n", arm_sdiv(val, 2));

  return 0;
}

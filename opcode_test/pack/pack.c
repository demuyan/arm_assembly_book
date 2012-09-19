#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_pkhbt(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm ("PKHBT %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_pkhbt_lsl(uint32_t v, uint32_t v2, uint32_t sh) {
  uint32_t d;
  asm ("PKHBT %[Rd], %[Rn], %[Rm], LSL %[sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2),[sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_pkhtb(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm ("PKHTB %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_pkhtb_asr(uint32_t v, uint32_t v2, uint32_t sh) {
  uint32_t d;
  asm ("PKHTB %[Rd], %[Rn], %[Rm], ASR %[sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2),[sh] "i" (sh));
  return d;
}


int main() {
  uint32_t val,val2;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  val = 0x00000010;
  printf("val2 = 0x%08X\n", val);
  printf("arm_pkhbt(val, val2) = 0x%08X\n", arm_pkhbt(val, val2));
  printf("arm_pkhbt_lsl(val, val2,2) = 0x%08X\n", arm_pkhbt_lsl(val, val2,2));

  printf("arm_pkhtb(val, val2) = 0x%08X\n", arm_pkhtb(val, val2));
  printf("arm_pkhtb_asr(val, val2,2) = 0x%08X\n", arm_pkhtb_asr(val, val2,2));


  return 0;
}

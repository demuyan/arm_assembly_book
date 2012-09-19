#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_sxtah(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("SXTAH %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtah_ror(uint32_t v,uint32_t v2,uint32_t sh) {
  uint32_t d;
  asm ("SXTAH %[Rd], %[Rn], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtab16(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("SXTAB16 %[Rd], %[Rn],%[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtab16_ror(uint32_t v,uint32_t v2,uint32_t sh) {
  uint32_t d;
  asm ("SXTAB16 %[Rd], %[Rn], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtab(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("SXTAB %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtab_ror(uint32_t v,uint32_t v2,uint32_t sh) {
  uint32_t d;
  asm ("SXTAB %[Rd], %[Rn], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2),[Sh] "i" (sh));
  return d;
}


int main() {
  uint32_t val,val2;

  val = 0x10203040;
  printf("val = 0x%08X\n", val);
  printf("arm_sxtah(val,2) = 0x%08X\n", arm_sxtah(val,2));
  printf("arm_sxtah_ror(val, 2,8) = 0x%08X\n", arm_sxtah_ror(val, 2,8));
  printf("arm_sxtah_ror(val, 2,16) = 0x%08X\n", arm_sxtah_ror(val, 2,16));
  printf("arm_sxtab16(val,2) = 0x%08X\n", arm_sxtab16(val,2));
  printf("arm_sxtab16_ror(val, 2,8) = 0x%08X\n", arm_sxtab16_ror(val, 2,8));
  printf("arm_sxtab16_ror(val, 2,16) = 0x%08X\n", arm_sxtab16_ror(val, 2,16));
  printf("arm_sxtab(val,2) = 0x%08X\n", arm_sxtab(val,2));
  printf("arm_sxtab_ror(val, 2,8) = 0x%08X\n", arm_sxtab_ror(val, 2,8));
  printf("arm_sxtab_ror(val, 2,16) = 0x%08X\n", arm_sxtab_ror(val, 2,16));


  return 0;
}

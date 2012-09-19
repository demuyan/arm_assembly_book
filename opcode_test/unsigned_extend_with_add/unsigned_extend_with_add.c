#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_uxtah(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("UXTAH %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtah_ror(uint32_t v,uint32_t v2,uint32_t sh) {
  uint32_t d;
  asm ("UXTAH %[Rd], %[Rn], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtab16(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("UXTAB16 %[Rd], %[Rn],%[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtab16_ror(uint32_t v,uint32_t v2,uint32_t sh) {
  uint32_t d;
  asm ("UXTAB16 %[Rd], %[Rn], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v),[Rm] "r" (v2),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtab(uint32_t v,uint32_t v2) {
  uint32_t d;
  asm ("UXTAB %[Rd], %[Rn], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtab_ror(uint32_t v,uint32_t v2,uint32_t sh) {
  uint32_t d;
  asm ("UXTAB %[Rd], %[Rn], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Rm] "r" (v2),[Sh] "i" (sh));
  return d;
}


int main() {
  uint32_t val,val2;

  val = 0x10203040;
  printf("val = 0x%08X\n", val);
  printf("arm_uxtah(val,2) = 0x%08X\n", arm_uxtah(val,2));
  printf("arm_uxtah_ror(val, 2,8) = 0x%08X\n", arm_uxtah_ror(val, 2,8));
  printf("arm_uxtah_ror(val, 2,16) = 0x%08X\n", arm_uxtah_ror(val, 2,16));
  printf("arm_uxtab16(val,2) = 0x%08X\n", arm_uxtab16(val,2));
  printf("arm_uxtab16_ror(val, 2,8) = 0x%08X\n", arm_uxtab16_ror(val, 2,8));
  printf("arm_uxtab16_ror(val, 2,16) = 0x%08X\n", arm_uxtab16_ror(val, 2,16));
  printf("arm_uxtab(val,2) = 0x%08X\n", arm_uxtab(val,2));
  printf("arm_uxtab_ror(val, 2,8) = 0x%08X\n", arm_uxtab_ror(val, 2,8));
  printf("arm_uxtab_ror(val, 2,16) = 0x%08X\n", arm_uxtab_ror(val, 2,16));


  return 0;
}

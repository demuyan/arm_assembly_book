#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_uxth(uint32_t v) {
  uint32_t d;
  asm ("UXTH %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxth_ror(uint32_t v,uint32_t sh) {
  uint32_t d;
  asm ("UXTH %[Rd], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtb16(uint32_t v) {
  uint32_t d;
  asm ("UXTB16 %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtb16_ror(uint32_t v,uint32_t sh) {
  uint32_t d;
  asm ("UXTB16 %[Rd], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtb(uint32_t v) {
  uint32_t d;
  asm ("UXTB %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uxtb_ror(uint32_t v,uint32_t sh) {
  uint32_t d;
  asm ("UXTB %[Rd], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[Sh] "i" (sh));
  return d;
}


int main() {
  uint32_t val,val2;

  val = 0x10203040;
  printf("val = 0x%08X\n", val);
  printf("arm_uxth(val) = 0x%08X\n", arm_uxth(val));
  printf("arm_uxth_ror(val, 8) = 0x%08X\n", arm_uxth_ror(val, 8));
  printf("arm_uxth_ror(val, 16) = 0x%08X\n", arm_uxth_ror(val, 16));
  printf("arm_uxtb16(val) = 0x%08X\n", arm_uxtb16(val));
  printf("arm_uxtb16_ror(val, 8) = 0x%08X\n", arm_uxtb16_ror(val, 8));
  printf("arm_uxtb16_ror(val, 16) = 0x%08X\n", arm_uxtb16_ror(val, 16));
  printf("arm_uxtb(val) = 0x%08X\n", arm_uxtb(val));
  printf("arm_uxtb_ror(val, 8) = 0x%08X\n", arm_uxtb_ror(val, 8));
  printf("arm_uxtb_ror(val, 16) = 0x%08X\n", arm_uxtb_ror(val, 16));


  return 0;
}

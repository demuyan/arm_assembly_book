#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_sxth(uint32_t v) {
  uint32_t d;
  asm ("SXTH %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxth_ror(uint32_t v,uint32_t sh) {
  uint32_t d;
  asm ("SXTH %[Rd], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtb16(uint32_t v) {
  uint32_t d;
  asm ("SXTB16 %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtb16_ror(uint32_t v,uint32_t sh) {
  uint32_t d;
  asm ("SXTB16 %[Rd], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[Sh] "i" (sh));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtb(uint32_t v) {
  uint32_t d;
  asm ("SXTB %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sxtb_ror(uint32_t v,uint32_t sh) {
  uint32_t d;
  asm ("SXTB %[Rd], %[Rm], ROR %[Sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[Sh] "i" (sh));
  return d;
}


int main() {
  uint32_t val,val2;

  val = 0x10203040;
  printf("val = 0x%08X\n", val);
  printf("arm_sxth(val) = 0x%08X\n", arm_sxth(val));
  printf("arm_sxth_ror(val, 8) = 0x%08X\n", arm_sxth_ror(val, 8));
  printf("arm_sxth_ror(val, 16) = 0x%08X\n", arm_sxth_ror(val, 16));
  printf("arm_sxtb16(val) = 0x%08X\n", arm_sxtb16(val));
  printf("arm_sxtb16_ror(val, 8) = 0x%08X\n", arm_sxtb16_ror(val, 8));
  printf("arm_sxtb16_ror(val, 16) = 0x%08X\n", arm_sxtb16_ror(val, 16));
  printf("arm_sxtb(val) = 0x%08X\n", arm_sxtb(val));
  printf("arm_sxtb_ror(val, 8) = 0x%08X\n", arm_sxtb_ror(val, 8));
  printf("arm_sxtb_ror(val, 16) = 0x%08X\n", arm_sxtb_ror(val, 16));


  return 0;
}

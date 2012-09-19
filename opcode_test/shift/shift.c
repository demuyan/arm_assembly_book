#include <stdio.h>
#include <stdint.h>


static inline __attribute__((always_inline))
uint32_t arm_asr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("ASR %[Rd], %[Rm], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_asr_r(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("ASR %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "i" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_lsl_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("LSL %[Rd], %[Rm], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_lsl_r(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("LSL %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "i" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_lsr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("LSR %[Rd], %[Rm], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_lsr_r(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("LSR %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "i" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_ror_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("ROR %[Rd], %[Rm], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_ror_r(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("ROR %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "i" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rrx(uint32_t v) {
  uint32_t d;
  asm ("RRX %[Rd], %[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v));
  return d;
}


int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("arm_asr_imm(val, 1) = 0x%08X\n", arm_asr_imm(val, 1));
  printf("arm_asr_r(val, 1) = 0x%08X\n", arm_asr_r(val, 1));
  printf("arm_lsl_imm(val, 1) = 0x%08X\n", arm_lsl_imm(val, 1));
  printf("arm_lsl_r(val, 1) = 0x%08X\n", arm_lsl_r(val, 1));
  printf("arm_lsr_imm(val, 1) = 0x%08X\n", arm_lsr_imm(val, 1));
  printf("arm_lsr_r(val, 1) = 0x%08X\n", arm_lsr_r(val, 1));
  printf("arm_ror_imm(val, 1) = 0x%08X\n", arm_ror_imm(val, 1));
  printf("arm_ror_r(val, 1) = 0x%08X\n", arm_ror_r(val, 1));
  printf("arm_rrx(val, 1) = 0x%08X\n", arm_rrx(val));

  return 0;
}

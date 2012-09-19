#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_add_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("ADD %[Rd], %[Rm], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_adc_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm (
    "MRS r1,cpsr\n\t"
    "ORR r1,r1,#0x20000000\n\t"
    "MSR cpsr_f,r1\n\t"
    "ADC %[Rd], %[Rm], %[Imm]\n\t" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Imm] "i" (imm)
    : "r1");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_add_lsl(uint32_t v, uint32_t v2, uint32_t imm) {
  uint32_t d;
  asm (
    "ADD %[Rd], %[Rm], %[Rn], LSL %[Imm]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_add_lsr(uint32_t v, uint32_t v2, uint32_t imm) {
  uint32_t d;
  asm ("ADD %[Rd], %[Rm], %[Rn], LSR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_add_asr(uint32_t v, uint32_t v2, uint32_t imm) {
  uint32_t d;
  asm ("ADD %[Rd], %[Rm], %[Rn], ASR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_add_ror(uint32_t v, uint32_t v2, uint32_t imm) {
  uint32_t d;
  asm ("ADD %[Rd], %[Rm], %[Rn], ROR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_qadd(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm ("QADD %[Rd], %[Rm], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}


int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("arm_add_imm(val, 1) = 0x%08X\n", arm_add_imm(val, 1));
  printf("arm_adc_imm(val, 1) = 0x%08X\n", arm_adc_imm(val, 1));
  printf("arm_add_lsl(val, 1,1) = 0x%08X\n", arm_add_lsl(val, 1,1));
  printf("arm_add_lsl(val, 1,2) = 0x%08X\n", arm_add_lsl(val, 1,2));
  printf("arm_add_lsl(val, 0x10,1) = 0x%08X\n", arm_add_lsl(val, 0x10,1));
  printf("arm_add_lsl(val, 0x10,2) = 0x%08X\n", arm_add_lsl(val, 0x10,2));
  printf("arm_add_lsr(val, 1,1) = 0x%08X\n", arm_add_lsr(val, 1,1));
  printf("arm_add_lsr(val, 1,2) = 0x%08X\n", arm_add_lsr(val, 1,2));
  printf("arm_add_lsr(val, 0x10,1) = 0x%08X\n", arm_add_lsr(val, 0x10,1));
  printf("arm_add_lsr(val, 0x10,2) = 0x%08X\n", arm_add_lsr(val, 0x10,2));
  printf("arm_add_asr(val, 1,1) = 0x%08X\n", arm_add_asr(val, 1,1));
  printf("arm_add_asr(val, 1,2) = 0x%08X\n", arm_add_asr(val, 1,2));
  printf("arm_add_asr(val, 0x10,1) = 0x%08X\n", arm_add_asr(val, 0x10,1));
  printf("arm_add_asr(val, 0x10,2) = 0x%08X\n", arm_add_asr(val, 0x10,2));
  printf("arm_add_ror(val, 1,1) = 0x%08X\n", arm_add_ror(val, 1,1));
  printf("arm_add_ror(val, 1,2) = 0x%08X\n", arm_add_ror(val, 1,2));
  printf("arm_add_ror(val, 0x10,1) = 0x%08X\n", arm_add_ror(val, 0x10,1));
  printf("arm_add_ror(val, 0x10,2) = 0x%08X\n", arm_add_ror(val, 0x10,2));

  val = 0x7ffffffe;
  printf("val = 0x%08X\n", val);
  printf("arm_qadd(val, 3) = 0x%08X\n", arm_qadd(val, 3));

  return 0;
}

#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_cmp(uint32_t v, uint32_t imm) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmn(uint32_t v, uint32_t imm) {
  uint32_t d=v;
  asm ("CMN %[Rd], %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_lsl_imm(uint32_t v,uint32_t v2, uint32_t imm) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], LSL %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_lsr_imm(uint32_t v, uint32_t v2, uint32_t imm) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], LSR %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_asr_imm(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], ASR %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_ror_imm(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], ROR %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_cmp_lsl_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], LSL %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_lsr_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], LSR %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_asr_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], ASR %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_cmp_ror_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("CMP %[Rd], %[Rm], ROR %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}


int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("arm_cmp(val, 1) = 0x%08X\n", arm_cmp(val, 1));
  printf("arm_cmp_lsl_r(val, 2,1) = 0x%08X\n", arm_cmp_lsl_r(val,2,1));
  printf("arm_cmp_lsl_imm(val, 2,1) = 0x%08X\n", arm_cmp_lsl_imm(val,2,1));
  printf("arm_cmp_lsr_r(val, 2,1) = 0x%08X\n", arm_cmp_lsr_r(val,2,1));
  printf("arm_cmp_lsr_imm(val, 2,1) = 0x%08X\n", arm_cmp_lsr_imm(val,2,1));
  printf("arm_cmp_asr_r(val, 2,1) = 0x%08X\n", arm_cmp_asr_r(val,2,1));
  printf("arm_cmp_asr_imm(val, 2,1) = 0x%08X\n", arm_cmp_asr_imm(val,2,1));
  printf("arm_cmp_ror_r(val, 2,1) = 0x%08X\n", arm_cmp_ror_r(val,2,1));
  printf("arm_cmp_ror_imm(val, 2,1) = 0x%08X\n", arm_cmp_ror_imm(val,2,1));

  printf("arm_cmn(val, 1) = 0x%08X\n", arm_cmn(val, 1));


  return 0;
}

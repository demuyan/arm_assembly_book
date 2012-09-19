#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_tst(uint32_t v, uint32_t imm) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_lsl_imm(uint32_t v,uint32_t v2, uint32_t imm) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], LSL %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_lsr_imm(uint32_t v, uint32_t v2, uint32_t imm) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], LSR %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_asr_imm(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], ASR %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_ror_imm(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], ROR %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Imm] "i" (imm));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_tst_lsl_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], LSL %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_lsr_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], LSR %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_asr_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], ASR %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_tst_ror_r(uint32_t v, uint32_t v2,uint32_t rn) {
  uint32_t d=v;
  asm ("TST %[Rd], %[Rm], ROR %[Rn]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Rm] "r" (v2), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_teq(uint32_t v, uint32_t imm) {
  uint32_t d=v;
  asm ("TEQ %[Rd], %[Imm]\n\t" 
       "MRS %[Rd],cpsr\n\t"
       : [Rd] "+r" (d) 
       : [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_and_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("AND %[Rd], %[Rn], %[Imm]\n\t" 
       : [Rd] "+r" (d) 
       : [Rn] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_eor_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("EOR %[Rd], %[Rn], %[Imm]\n\t" 
       : [Rd] "+r" (d) 
       : [Rn] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_orr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("ORR %[Rd], %[Rn], %[Imm]\n\t" 
       : [Rd] "+r" (d) 
       : [Rn] "r" (v), [Imm] "i" (imm));
  return d;
}

/*
static inline __attribute__((always_inline))
uint32_t arm_orn_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("ORN %[Rd], %[Rn], %[Imm]\n\t" 
       : [Rd] "+r" (d) 
       : [Rn] "r" (v), [Imm] "i" (imm));
  return d;
}
*/

static inline __attribute__((always_inline))
uint32_t arm_bic_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("BIC %[Rd], %[Rn], %[Imm]\n\t" 
       : [Rd] "+r" (d) 
       : [Rn] "r" (v), [Imm] "i" (imm));
  return d;
}


int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("arm_tst(val, 1) = 0x%08X\n", arm_tst(val, 1));
  printf("arm_tst_lsl_r(val, 2,1) = 0x%08X\n", arm_tst_lsl_r(val,2,1));
  printf("arm_tst_lsl_imm(val, 2,1) = 0x%08X\n", arm_tst_lsl_imm(val,2,1));
  printf("arm_tst_lsr_r(val, 2,1) = 0x%08X\n", arm_tst_lsr_r(val,2,1));
  printf("arm_tst_lsr_imm(val, 2,1) = 0x%08X\n", arm_tst_lsr_imm(val,2,1));
  printf("arm_tst_asr_r(val, 2,1) = 0x%08X\n", arm_tst_asr_r(val,2,1));
  printf("arm_tst_asr_imm(val, 2,1) = 0x%08X\n", arm_tst_asr_imm(val,2,1));
  printf("arm_tst_ror_r(val, 2,1) = 0x%08X\n", arm_tst_ror_r(val,2,1));
  printf("arm_tst_ror_imm(val, 2,1) = 0x%08X\n", arm_tst_ror_imm(val,2,1));

  printf("arm_teq(val, 1) = 0x%08X\n", arm_teq(val, 1));

  printf("arm_and_imm(val, 1) = 0x%08X\n", arm_and_imm(val, 1));
  printf("arm_eor_imm(val, 1) = 0x%08X\n", arm_eor_imm(val, 1));
  printf("arm_orr_imm(val, 1) = 0x%08X\n", arm_orr_imm(val, 1));
//  printf("arm_orn_imm(val, 1) = 0x%08X\n", arm_orn_imm(val, 1)); // thumb2のみ
  printf("arm_bic_imm(val, 1) = 0x%08X\n", arm_bic_imm(val, 1));


  return 0;
}

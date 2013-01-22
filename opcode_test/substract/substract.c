#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_sub_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm (
    "MOV r1,%[Rm]\n\t"
    "MOV r2,%[Imm]\n\t"
    "SUB r3, r1, r2\n\t" 
    "MOV %[Rd],r3\n\t"
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Imm] "i" (imm)
    : "r1","r2","r3");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sbc_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm (
       "MRS r1,cpsr\n\t"
       "BIC r1,r1,#0x20000000\n\t"
       "MSR cpsr_f,r1\n\t"
       "SBC %[Rd], %[Rm], %[Imm]\n\t" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm)
       : "r1","cc");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sub_lsl(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("SUB %[Rd], %[Rm], %[Rn], LSL %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sub_lsr(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("SUB %[Rd], %[Rm], %[Rn], LSR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sub_asr(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("SUB %[Rd], %[Rm], %[Rn], ASR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_sub_ror(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("SUB %[Rd], %[Rm], %[Rn], ROR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rsb_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("RSB %[Rd], %[Rm], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rsb_lsl(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("RSB %[Rd], %[Rm], %[Rn], LSL %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rsb_lsr(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("RSB %[Rd], %[Rm], %[Rn], LSR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rsb_asr(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm ("RSB %[Rd], %[Rm], %[Rn], ASR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_rsb_ror(uint32_t v, uint32_t v2,uint32_t imm) {
  uint32_t d;
  asm (
    "RSB %[Rd], %[Rm], %[Rn], ROR %[Imm]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_qsub_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm (
    "MOV r1,%[Rm]\n\t"
    "MOV r2,%[Imm]\n\t"
    "QSUB r3, r1, r2\n\t" 
    "MOV %[Rd],r3\n\t"
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Imm] "i" (imm)
    : "r1","r2","r3");
  return d;
}



int main() {
  uint32_t val;

  val = 0x00000022;
  printf("val = 0x%08X\n", val);
  printf("arm_sub_imm(val, 1) = 0x%08X\n", arm_sub_imm(val, 1));
  printf("carry_flag clear\n");
  printf("arm_sbc_imm(val, 1) = 0x%08X\n", arm_sbc_imm(val, 1));
  printf("arm_sub_lsl(val, 1,1) = 0x%08X\n", arm_sub_lsl(val, 1,1));
  printf("arm_sub_lsl(val, 1,2) = 0x%08X\n", arm_sub_lsl(val, 1,2));
  printf("arm_sub_lsr(val, 1,1) = 0x%08X\n", arm_sub_lsr(val, 1,1));
  printf("arm_sub_lsr(val, 1,2) = 0x%08X\n", arm_sub_lsr(val, 1,2));
  printf("arm_sub_asr(val, 1,1) = 0x%08X\n", arm_sub_asr(val, 1,1));
  printf("arm_sub_asr(val, 1,2) = 0x%08X\n", arm_sub_asr(val, 1,2));
  printf("arm_sub_ror(val, 1,1) = 0x%08X\n", arm_sub_ror(val, 1,1));
  printf("arm_sub_ror(val, 1,2) = 0x%08X\n", arm_sub_ror(val, 1,2));

  printf("arm_rsb_imm(val, 0x53) = 0x%08X\n", arm_rsb_imm(val, 0x53));
  printf("arm_rsb_lsl(val, 1,1) = 0x%08X\n", arm_rsb_lsl(val, 1,1));
  printf("arm_rsb_lsl(val, 1,2) = 0x%08X\n", arm_rsb_lsl(val, 1,2));
  printf("arm_rsb_lsr(val, 1,1) = 0x%08X\n", arm_rsb_lsr(val, 1,1));
  printf("arm_rsb_lsr(val, 1,2) = 0x%08X\n", arm_rsb_lsr(val, 1,2));
  printf("arm_rsb_asr(val, 1,1) = 0x%08X\n", arm_rsb_asr(val, 1,1));
  printf("arm_rsb_asr(val, 1,2) = 0x%08X\n", arm_rsb_asr(val, 1,2));
  printf("arm_rsb_ror(val, 1,1) = 0x%08X\n", arm_rsb_ror(val, 1,1));
  printf("arm_rsb_ror(val, 1,2) = 0x%08X\n", arm_rsb_ror(val, 1,2));

  val = 0x80000001;
  printf("val = 0x%08X\n", val);
  printf("arm_qsub_imm(val, 3) = 0x%08X\n", arm_qsub_imm(val, 3));



  return 0;
}

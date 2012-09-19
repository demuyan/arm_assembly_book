#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_mov(uint32_t imm) {
  uint32_t d;
  asm ("MOV %[Rd], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_lsl_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], LSL %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_lsr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], LSR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_asr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], ASR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_ror_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], ROR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_mov_lsl_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], LSL %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_lsr_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], LSR %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_asr_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], ASR %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mov_ror_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MOV %[Rd], %[Rm], ROR %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn(uint32_t imm) {
  uint32_t d;
  asm ("MVN %[Rd], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_lsl_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], LSL %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_lsr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], LSR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_asr_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], ASR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_ror_imm(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], ROR %[Imm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_mvn_lsl_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], LSL %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_lsr_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], LSR %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_asr_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], ASR %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mvn_ror_r(uint32_t v, uint32_t rn) {
  uint32_t d;
  asm ("MVN %[Rd], %[Rm], ROR %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rn] "r" (rn));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_movt(uint32_t imm) {
  uint32_t d;
  asm ("MOVT %[Rd], %[Imm]" 
       : [Rd] "=r" (d) 
       : [Imm] "i" (imm));
  return d;
}

int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = 0x%08X\n", val);
  printf("arm_mov(val, 1) = 0x%08X\n", arm_mov(val));
  printf("arm_mov_lsl_imm(val, 1) = 0x%08X\n", arm_mov_lsl_imm(val, 1));
  printf("arm_mov_lsr_imm(val, 1) = 0x%08X\n", arm_mov_lsr_imm(val, 1));
  printf("arm_mov_asr_imm(val, 1) = 0x%08X\n", arm_mov_asr_imm(val, 1));
  printf("arm_mov_ror_imm(val, 1) = 0x%08X\n", arm_mov_ror_imm(val, 1));
  printf("arm_mov_lsl_r(val, 1) = 0x%08X\n", arm_mov_lsl_r(val, 1));
  printf("arm_mov_lsr_r(val, 1) = 0x%08X\n", arm_mov_lsr_r(val, 1));
  printf("arm_mov_asr_r(val, 1) = 0x%08X\n", arm_mov_asr_r(val, 1));
  printf("arm_mov_ror_r(val, 1) = 0x%08X\n", arm_mov_ror_r(val, 1));

  printf("arm_mvn(val, 1) = 0x%08X\n", arm_mvn(val));
  printf("arm_mvn_lsl_imm(val, 1) = 0x%08X\n", arm_mvn_lsl_imm(val, 1));
  printf("arm_mvn_lsr_imm(val, 1) = 0x%08X\n", arm_mvn_lsr_imm(val, 1));
  printf("arm_mvn_asr_imm(val, 1) = 0x%08X\n", arm_mvn_asr_imm(val, 1));
  printf("arm_mvn_ror_imm(val, 1) = 0x%08X\n", arm_mvn_ror_imm(val, 1));
  printf("arm_mvn_lsl_r(val, 1) = 0x%08X\n", arm_mvn_lsl_r(val, 1));
  printf("arm_mvn_lsr_r(val, 1) = 0x%08X\n", arm_mvn_lsr_r(val, 1));
  printf("arm_mvn_asr_r(val, 1) = 0x%08X\n", arm_mvn_asr_r(val, 1));
  printf("arm_mvn_ror_r(val, 1) = 0x%08X\n", arm_mvn_ror_r(val, 1));


  printf("arm_movt(val, 1) = 0x%08X\n", arm_movt(val));

  return 0;
}

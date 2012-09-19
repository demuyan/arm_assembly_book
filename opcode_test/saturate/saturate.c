#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_ssat(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("SSAT %[Rd], %[Imm],%[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_ssat_asr(uint32_t v, uint32_t imm, uint32_t sh) {
  uint32_t d;
  asm ("SSAT %[Rd], %[Imm],%[Rm], ASR %[sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[sh] "i" (sh),[Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_ssat_lsl(uint32_t v, uint32_t imm, uint32_t sh) {
  uint32_t d;
  asm ("SSAT %[Rd], %[Imm],%[Rm], LSL %[sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[sh] "i" (sh),[Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_ssat16(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("SSAT16 %[Rd], %[Imm],%[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_usat(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("USAT %[Rd], %[Imm],%[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_usat_asr(uint32_t v, uint32_t imm, uint32_t sh) {
  uint32_t d;
  asm ("USAT %[Rd], %[Imm],%[Rm], ASR %[sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[sh] "i" (sh),[Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_usat_lsl(uint32_t v, uint32_t imm, uint32_t sh) {
  uint32_t d;
  asm ("USAT %[Rd], %[Imm],%[Rm], LSL %[sh]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v),[sh] "i" (sh),[Imm] "i" (imm));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_usat16(uint32_t v, uint32_t imm) {
  uint32_t d;
  asm ("USAT16 %[Rd], %[Imm],%[Rm]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Imm] "i" (imm));
  return d;
}






int main() {
  uint32_t val;

  val = 0x12345678;
  printf("val = 0x%08X\n", val);
  printf("arm_ssat(val, 1) = 0x%08X\n", arm_ssat(val, 1));
  printf("arm_ssat(val, 3) = 0x%08X\n", arm_ssat(val, 3));
  printf("arm_ssat(val, 5) = 0x%08X\n", arm_ssat(val, 5));
  printf("arm_ssat16(val, 1) = 0x%08X\n", arm_ssat16(val, 1));
  printf("arm_ssat16(val, 3) = 0x%08X\n", arm_ssat16(val, 3));
  printf("arm_ssat16(val, 5) = 0x%08X\n", arm_ssat16(val, 5));
  printf("arm_usat(val, 1) = 0x%08X\n", arm_usat(val, 1));
  printf("arm_usat(val, 3) = 0x%08X\n", arm_usat(val, 3));
  printf("arm_usat(val, 5) = 0x%08X\n", arm_usat(val, 5));
  printf("arm_usat16(val, 1) = 0x%08X\n", arm_usat16(val, 1));
  printf("arm_usat16(val, 3) = 0x%08X\n", arm_usat16(val, 3));
  printf("arm_usat16(val, 5) = 0x%08X\n", arm_usat16(val, 5));

  val = 0x1fffffff;
  printf("val = 0x%08X\n", val);
  printf("arm_ssat_asr(val, 5,1) = 0x%08X\n", arm_ssat_asr(val, 4,1));
  printf("arm_ssat_lsl(val, 5,1) = 0x%08X\n", arm_ssat_lsl(val, 4,1));
  printf("arm_usat_asr(val, 5,1) = 0x%08X\n", arm_usat_asr(val, 4,1));
  printf("arm_usat_lsl(val, 5,1) = 0x%08X\n", arm_usat_lsl(val, 4,1));

  val = 0x7fffffff;
  printf("val = 0x%08X\n", val);
  printf("arm_ssat_asr(val, 5,1) = 0x%08X\n", arm_ssat_asr(val, 4,1));
  printf("arm_ssat_lsl(val, 5,1) = 0x%08X\n", arm_ssat_lsl(val, 4,1));
  printf("arm_usat_asr(val, 5,1) = 0x%08X\n", arm_usat_asr(val, 4,1));
  printf("arm_usat_lsl(val, 5,1) = 0x%08X\n", arm_usat_lsl(val, 4,1));
  return 0;
}

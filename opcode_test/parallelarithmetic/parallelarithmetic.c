#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_qadd16(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QADD16 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_qsub16(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QSUB16 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_qadd8(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QADD8 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_qsub8(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QSUB8 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_qasx(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QASX %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_qsax(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QSAX %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}




static inline __attribute__((always_inline))
uint32_t arm_uqadd16(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UQADD16 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_uqsub16(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UQSUB16 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_uqadd8(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UQADD8 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_uqsub8(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UQSUB8 %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}


static inline __attribute__((always_inline))
uint32_t arm_uqasx(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UQASX %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_uqsax(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "UQSAX %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_usad8(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QSAX %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

uint32_t arm_usada8(uint32_t v, uint32_t v2) {
  uint32_t d;
  asm (
    "QSAX %[Rd], %[Rm], %[Rn]" 
    : [Rd] "=r" (d) 
    : [Rm] "r" (v), [Rn] "r" (v2));
  return d;
}

int main() {
  uint32_t val;

  val = 0x10203040;
  printf("val = 0x%08X\n", val);

  printf("arm_qadd16(val, 0x00ff00ff) = 0x%08X\n", arm_qadd16(val, 0x00ff00ff));
  printf("arm_qsub16(val, 0x00ff00ff) = 0x%08X\n", arm_qsub16(val, 0x00ff00ff));
  printf("arm_qadd8(val, 0x00ff00ff) = 0x%08X\n", arm_qadd8(val, 0x00ff00ff));
  printf("arm_qsub8(val, 0x00ff00ff) = 0x%08X\n", arm_qsub8(val, 0x00ff00ff));
  printf("arm_qasx(val, 0x00ff00ff) = 0x%08X\n", arm_qasx(val, 0x00ff00ff));
  printf("arm_qsax(val, 0x00ff00ff) = 0x%08X\n", arm_qsax(val, 0x00ff00ff));
  printf("\n");
  printf("arm_uqadd16(val, 0x00ff00ff) = 0x%08X\n", arm_uqadd16(val, 0x00ff00ff));
  printf("arm_uqsub16(val, 0x00ff00ff) = 0x%08X\n", arm_uqsub16(val, 0x00ff00ff));
  printf("arm_uqadd8(val, 0x00ff00ff) = 0x%08X\n", arm_uqadd8(val, 0x00ff00ff));
  printf("arm_uqsub8(val, 0x00ff00ff) = 0x%08X\n", arm_uqsub8(val, 0x00ff00ff));
  printf("arm_uqasx(val, 0x00ff00ff) = 0x%08X\n", arm_uqasx(val, 0x00ff00ff));
  printf("arm_uqsax(val, 0x00ff00ff) = 0x%08X\n", arm_uqsax(val, 0x00ff00ff));
  printf("\n");
  printf("arm_usad8(val, 0x00ff00ff) = 0x%08X\n", arm_usad8(val, 0x00ff00ff));
  printf("arm_usada8(val, 0x00ff00ff) = 0x%08X\n", arm_usada8(val, 0x00ff00ff));

  return 0;
}

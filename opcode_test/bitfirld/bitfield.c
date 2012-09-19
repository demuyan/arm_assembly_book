#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t thumb2_bfc(uint32_t v, uint32_t width) {
  uint32_t d;
  asm ("BFC %[Rd], %[Lsb], %[Width]" 
       : [Rd] "=r" (d) 
       : [Lsb] "i" (v), [Width] "i" (width));
  return d;
}

static inline __attribute__((always_inline))
uint32_t thumb2_bfi(uint32_t v, uint32_t lsb, uint32_t width) {
  uint32_t d;
  asm ("BFI %[Rd], %[Rn], %[Lsb], %[Width]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Lsb] "i" (lsb), [Width] "i" (width));
  return d;
}

static inline __attribute__((always_inline))
uint32_t thumb2_sbfx(uint32_t v, uint32_t lsb, uint32_t width) {
  uint32_t d;
  asm ("SBFX %[Rd], %[Rn], %[Lsb], %[Width]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Lsb] "i" (lsb), [Width] "i" (width));
  return d;
}

static inline __attribute__((always_inline))
uint32_t thumb2_ubfx(uint32_t v, uint32_t lsb, uint32_t width) {
  uint32_t d;
  asm ("UBFX %[Rd], %[Rn], %[Lsb], %[Width]" 
       : [Rd] "=r" (d) 
       : [Rn] "r" (v), [Lsb] "i" (lsb), [Width] "i" (width));
  return d;
}

// すべてthumb-2命令
int main() {
  uint32_t val;

  val = 0x00000003;
  printf("val = 0x%08X\n", val);
  printf("thumb2_bfc(val, 1) = 0x%08X\n", thumb2_bfc(val, 1));
  printf("thumb2_bfi(val, 2, 1) = 0x%08X\n", thumb2_bfi(val, 2,1));
  printf("thumb2_sbfx(val, 1,1) = 0x%08X\n", thumb2_sbfx(val, 1,1));
  printf("thumb2_ubfx(val, 1,2) = 0x%08X\n", thumb2_ubfx(val, 1,1));

  return 0;
}

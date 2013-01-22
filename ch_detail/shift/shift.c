#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_shift_sample_1(uint32_t imm) {
  uint32_t d;
  __asm__ (
    "MOV r0,%[Imm]       \n\t" 
    "ADD r0,r0,r0 @  2倍 \n\t" 
    "ADD r0,r0,r0 @  4倍 \n\t" 
    "ADD r0,r0,r0 @  8倍 \n\t" 
    "ADD r0,r0,r0 @ 16倍 \n\t" 
    "MOV %[Rd],r0        \n\t" 
    : [Rd] "=r" (d) 
    : [Imm] "i" (imm)
    : "r0","r1","r2","r3");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_shift_sample_2(uint32_t imm) {
  uint32_t d;
  __asm__ (
    "MOV r0,%[Imm]                \n\t" 
    "LSL r0,r0,#4 @ 4bit左シフト  \n\t" 
    "MOV %[Rd],r0                 \n\t" 
    : [Rd] "=r" (d) 
    : [Imm] "i" (imm)
    : "r0","r1","r2","r3");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_shift_sample_3(uint32_t imm) {
  uint32_t d;
  __asm__ (
    "MOV r0,%[Imm]                \n\t" 
    "LSL r1,r0,#1                 \n\t" 
    "LSL r2,r0,#2                 \n\t" 
    "ADD r3,r1,r2                 \n\t" 
    "ADD r3,r3,r0                 \n\t" 
    "MOV %[Rd],r3                 \n\t" 
    : [Rd] "=r" (d) 
    : [Imm] "i" (imm)
    : "r0","r1","r2","r3");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_shift_sample_4(uint32_t imm) {
  uint32_t d;
  __asm__ (
    "MOV r0,%[Imm]                \n\t" 
    "LSL r1,r0,#3                 \n\t" 
    "SUB %[Rd],r1,r0              \n\t" 
    : [Rd] "=r" (d) 
    : [Imm] "i" (imm)
    : "r0","r1","r2","r3");
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_logical_shift_1() {
  int32_t rd1,rd2,rd3,rd4;
  int32_t imm1=10;
  int32_t imm2=-10;
  __asm__ (
    "MOV r0,%[Imm1]              \n\t" 
    "LSL %[Rd1],r0,#1            \n\t" 
    "LSR %[Rd2],r0,#1            \n\t" 
    "MOV r0,%[Imm2]              \n\t" 
    "LSL %[Rd3],r0,#1            \n\t" 
    "LSR %[Rd4],r0,#1            \n\t" 
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[Rd3] "=r" (rd3) ,[Rd4] "=r" (rd4) 
    : [Imm1] "i" (imm1), [Imm2] "i" (imm2) 
    : "r0","r1","r2","r3");

  printf("MOV r0,#%d   @ r0= %d\n",imm1,imm1);
  printf("LSL r1,r0,#1 @ r1= %d\n",rd1);
  printf("LSR r2,r0,#1 @ r2= %d\n",rd2);
  printf("\n");
  printf("MOV r0,#%d   @ r0= %d\n",imm2,imm2);
  printf("LSL r1,r0,#1 @ r1= %d\n",rd3);
  printf("LSR r2,r0,#1 @ r2= %d\n",rd4);

  return -99;
}

static inline __attribute__((always_inline))
uint32_t arm_arithmetic_shift_sample_1() {
  int32_t rd1,rd2,rd3,rd4;
  int32_t imm1=10;
  int32_t imm2=-10;
  __asm__ (
    "MOV r0,%[Imm1]                \n\t" 
    "ASR %[Rd1],r0,#1              \n\t" 
    "MOV r0,%[Imm2]                \n\t" 
    "ASR %[Rd2],r0,#1              \n\t" 
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[Rd3] "=r" (rd3) ,[Rd4] "=r" (rd4) 
    : [Imm1] "i" (imm1), [Imm2] "i" (imm2) 
    : "r0","r1","r2","r3");

  printf("MOV r0,#%d   @ r0= %d\n",imm1,imm1);
  printf("ASR r1,r0,#1 @ r1= %d\n",rd1);
  printf("MOV r0,#%d  @ r0= %d\n",imm2,imm2);
  printf("ASR r1,r0,#1 @ r1= %d\n",rd2);
  
  return -99;
}

static inline __attribute__((always_inline))
uint32_t arm_rotate_shift_sample_1() {
  int32_t rd1,rd2,rd3,rd4;
  int32_t imm1=10,imm2=-10;
  __asm__ (
    "MOV r0,%[Imm1]                \n\t" 
    "ROR %[Rd1],r0,#1              \n\t" 
    "ROR %[Rd2],r0,#2              \n\t" 
    "ROR %[Rd3],r0,#30              \n\t" 
    "ROR %[Rd4],r0,#31              \n\t" 
    : [Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[Rd3] "=r" (rd3) ,[Rd4] "=r" (rd4) 
    : [Imm1] "i" (imm1), [Imm2] "i" (imm2) 
    : "r0","r1","r2","r3");

  printf("\n");
  printf("MOV r0,#%d   @ r0= %d\n",imm1,imm1);
  printf("ROR r1,r0,#1 @ r1= %d\n",rd1);
  printf("ROR r2,r0,#2 @ r2= %d\n",rd2);
  printf("ROR r3,r0,#30 @ r3= %d\n",rd3);
  printf("ROR r4,r0,#31 @ r4= %d\n",rd4);
  
  return -99;
}

static inline __attribute__((always_inline))
uint32_t arm_rotate_shift_sample_2() {
  int32_t rd1,rd2,rd3,rd4,rd5,rd6,rd7,rd8,rd9,rd10;
  int32_t imm1=-1,imm2=0;
  __asm__ (
    "      ADDS r0,r0,#0             \n\t"
    "      MOV r0,%[Imm1]             \n\t" 
    "      MOV r1,#32                \n\t" 
    "      MOV r2,#0                 \n\t" 
    "LOOP: RRXS r0,r0                 \n\t" 
    "      BLCC SKIP                  \n\t" 
    "      ADD r2,r2,#1                 \n\t" 
    "SKIP: SUBS r1,r1,#1                  \n\t" 
    "      BNE LOOP                  \n\t" 
    "      MOV %[Rd1],r2              \n\t" 
    : [Rd1] "=r" (rd1)
    : [Imm1] "i" (imm1), [Imm2] "i" (imm2) 
    : "r0","r1","r2","r3");

  printf("\n");
  printf("Rd1=0x%08X\n",rd1);  
  return -99;
}

int main() {
  uint32_t val;

  val = 0x00000005;
  printf("val = %d\n", val);
  printf("arm_shift_sample_1(val) = %d\n",arm_shift_sample_1(val));
  printf("arm_shift_sample_2(val) = %d\n",arm_shift_sample_2(val));
  printf("arm_shift_sample_3(val) = %d\n",arm_shift_sample_3(val));
  printf("arm_shift_sample_4(val) = %d\n",arm_shift_sample_4(val));
  arm_logical_shift_1();
  arm_arithmetic_shift_sample_1();
  arm_rotate_shift_sample_1();
  arm_rotate_shift_sample_2();

  return 0;
}

#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"
/////begin ch_detail_shift_1
/*
 * 加算命令のみで値を16倍する
 */
void arm_shift_1(void) {
  uint32_t d;
  __asm__ (
    "MOV r0,#5           \n\t" 
    "ADD r0,r0,r0        \n\t" /* 2倍 */
    "ADD r0,r0,r0        \n\t" /* 4倍 */
    "ADD r0,r0,r0        \n\t" /* 8倍 */
    "ADD r0,r0,r0        \n\t" /* 16倍 */
    "MOV %[Rd],r0        \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0");

  printf("r0 = %d\n",d);
}
/////end
/////begin ch_detail_shift_2
/*
 * シフト命令を使って16倍する
 */
void arm_shift_2(void) {
  uint32_t d;
  __asm__ (
    "MOV r0,#5         \n\t" 
    "LSL r0,r0,#4      \n\t" /* 4ビット左シフト */
    "MOV %[Rd],r0      \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");

  printf("r0 = %d\n",d);
}
/////end
/////begin ch_detail_shift_3
/*
 * 値を７倍する
 */
void arm_shift_3(void) {
  uint32_t rd0;
  __asm__ (
    "MOV r0,#5       \n\t" 
    "LSL r1,r0,#1    \n\t" /* 2倍 */
    "LSL r2,r0,#2    \n\t" /* 4倍 */
    "ADD r3,r1,r2    \n\t" 
    "ADD r3,r3,r0    \n\t" /* 7倍 */
    "MOV %[Rd0],r3    \n\t" 
    : [Rd0] "=r" (rd0) 
    : 
    : "r0","r1","r2","r3");

  printf("r0 = %d\n",rd0);
}
/////end
/////begin ch_detail_shift_4
/*
 * 値を７倍する
 */
void arm_shift_4(void) {
  uint32_t rd0;
  __asm__ (
    "MOV r0,#5       \n\t" 
    "LSL r1,r0,#3    \n\t" 
    "SUB r2,r1,r0    \n\t" 
    "MOV %[Rd0],r2    \n\t" 
    : [Rd0] "=r" (rd0) 
    : 
    : "r0","r1","r2","r3");

  printf("r0 = %d\n",rd0);
}
/////end
/////begin ch_detail_logical_shift_1
/*
 * 論理シフト
 */
void arm_logical_shift_1() {
  int32_t rd0,rd1,rd2,rd3,rd4;
  __asm__ (
    "MOV r0,#10       \n\t" 
    "LSL r1,r0,#1     \n\t" 
    "LSR r2,r0,#1     \n\t"
    "MOV %[Rd0],r0    \n\t" 
    "MOV %[Rd1],r1    \n\t" 
    "MOV %[Rd2],r2    \n\t" 
    : [Rd0] "=r" (rd0) ,[Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2","r3","r4");

  printf("r0 = 0x%08x\n",rd0);
  printf("r1 = 0x%08x\n",rd1);
  printf("r2 = 0x%08x\n",rd2);
}
/////end
/////begin ch_detail_logical_shift_2
/*
 * 論理シフト
 */
void arm_logical_shift_2() {
  int32_t rd0, rd1,rd2,rd3,rd4;
  __asm__ (
    "MOV r0,#-10      \n\t" 
    "LSL r1,r0,#1     \n\t" 
    "LSR r2,r0,#1     \n\t" 
    "MOV %[Rd0],r0    \n\t" 
    "MOV %[Rd1],r1    \n\t" 
    "MOV %[Rd2],r2    \n\t" 
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2","r3","r4");

  printf("r0 = 0x%08x\n",rd0);
  printf("r1 = 0x%08x\n",rd1);
  printf("r2 = 0x%08x\n",rd2);

}
/////end
/////begin ch_detail_arithmetic_shift_1
/*
 * 正の値を算術シフトする
 */
void arm_arithmetic_shift_1() {
  int32_t rd0, rd1,rd2,rd3,rd4;
  __asm__ (
    "MOV r0,#10                \n\t" 
    "ASR r1,r0,#1              \n\t" 
    "MOV %[Rd0],r0    \n\t" 
    "MOV %[Rd1],r1    \n\t" 
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1)
    : 
    : "r0","r1","r2","r3");

  printf("r0 = 0x%08x\n",rd0);
  printf("r1 = 0x%08x\n",rd1);
}
/////end
/////begin ch_detail_arithmetic_shift_2
/*
 * 負の値を算術シフトする
 */
void arm_arithmetic_shift_2() {
  int32_t rd0, rd1,rd2,rd3,rd4;
  __asm__ (
    "MOV r0,#-10                \n\t" 
    "ASR r1,r0,#1              \n\t" 
    "MOV %[Rd0],r0    \n\t" 
    "MOV %[Rd1],r1    \n\t" 
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1)
    : 
    : "r0","r1","r2","r3");

  printf("r0 = 0x%08x\n",rd0);
  printf("r1 = 0x%08x\n",rd1);
}
/////end
/////begin ch_detail_rotate_shift_1
/*
 * ローテートシフト
 */
void arm_rotate_shift_1() {
  int32_t rd0, rd1,rd2,rd3,rd4;
  __asm__ (
    "MOV r0,#10                \n\t" 
    "ROR r1,r0,#1              \n\t" 
    "ROR r2,r0,#2              \n\t" 
    "ROR r3,r0,#30              \n\t" 
    "ROR r4,r0,#31              \n\t" 
    "MOV %[Rd1],r1    \n\t" 
    "MOV %[Rd2],r2    \n\t" 
    "MOV %[Rd3],r3    \n\t" 
    "MOV %[Rd4],r4    \n\t" 
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[Rd3] "=r" (rd3) ,[Rd4] "=r" (rd4) 
    : 
    : "r0","r1","r2","r3","r4");
  printf("r0 = 0x%08x\n",rd0);
  printf("r1 = 0x%08x\n",rd1);
  printf("r2 = 0x%08x\n",rd2);
  printf("r3 = 0x%08x\n",rd3);
  printf("r4 = 0x%08x\n",rd4);
}
/////end
/////begin ch_detail_rotate_shift_2
/*
 * ローテートシフト
 */
void arm_rotate_shift_2() {
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

  printf("r2=0x%08X\n",rd1);  
}
/////end


int main() {

  WRAP("ch_detail_shift_1_a", arm_shift_1);
  WRAP("ch_detail_shift_2_a", arm_shift_2);
  WRAP("ch_detail_shift_3_a", arm_shift_3);
  WRAP("ch_detail_shift_4_a", arm_shift_4);
  WRAP("ch_detail_logical_shift_1_a", arm_logical_shift_1);
  WRAP("ch_detail_logical_shift_2_a", arm_logical_shift_2);
  WRAP("ch_detail_arithmetic_shift_1_a", arm_arithmetic_shift_1);
  WRAP("ch_detail_arithmetic_shift_2_a", arm_arithmetic_shift_2);
  WRAP("ch_detail_rotate_shift_1_a", arm_rotate_shift_1);
  WRAP("ch_detail_rotate_shift_2_a", arm_rotate_shift_2);

  return 0;
}

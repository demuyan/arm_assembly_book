#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"
/*
 * 加算命令のみで値を16倍する
 */
void arm_shift_1(void) {
  uint32_t d;
  __asm__ (
    "LDR r0,=5    \n\t" // r0 ← 5 
    "ADD r0,r0,r0 \n\t" // 2倍
    "ADD r0,r0,r0 \n\t" // 4倍
    "ADD r0,r0,r0 \n\t" // 8倍
    "ADD r0,r0,r0 \n\t" // 16倍
    "MOV %[Rd],r0 \n\t" 
    : [Rd] "=r" (d) 
    : 
    : "r0");

  printf("r0 = %d\n",d);
}

/*
 * シフト命令を使って16倍する
 */
void arm_shift_2(void) {
  uint32_t d;
  __asm__ (
    "LDR r0,=5    \n\t" // r0 ← 5 
    "LSL r0,r0,#4 \n\t" // r0 ← r0の値を4ビット分論理左シフト
    "MOV %[Rd],r0 \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0");

  printf("r0 = %d\n",d);
}

/*
 * 値を７倍する
 */
void arm_shift_3(void) {
  uint32_t rd0;
  __asm__ (
    "LDR r0,=5     \n\t" // r0 ← 5 
    "LSL r1,r0,#1  \n\t" // r1 ← r0 * 2 
    "LSL r2,r0,#2  \n\t" // r2 ← r0 * 4
    "ADD r3,r1,r2  \n\t" // r3 ← r0 * 6 = (r0 * 2) + (r0 * 4) 
    "ADD r3,r3,r0  \n\t" // r3 ← r0 * 7 = (r0 * 6) + r0
    "MOV %[Rd0],r3 \n\t" // 変数rd0 ← r3
    : [Rd0] "=r" (rd0) 
    : 
    : "r0","r1","r2","r3");

  printf("r0 = %d\n",rd0);
}

/*
 * 値を７倍する
 */
void arm_shift_4(void) {
  uint32_t rd0;
  __asm__ (
    "LDR r0,=5     \n\t" // r0 ← 5 
    "LSL r1,r0,#3  \n\t" // r1 ← r0の値を3ビット分左論理シフト(=8倍)
    "SUB r2,r1,r0  \n\t" // r2 ← r1 - r0
    "MOV %[Rd0],r2 \n\t" // 変数rd0 ← r2
    : [Rd0] "=r" (rd0) 
    : 
    : "r0","r1","r2");

  printf("r0 = %d\n",rd0);
}

/*
 * 論理シフト
 */
void arm_logical_shift_1() {
  int32_t rd0,rd1,rd2;
  __asm__ (
    "LDR r0,=10    \n\t"   // r0 ← 10 
    "LSL r1,r0,#1  \n\t" // 論理左シフト(１ビット分)
    "LSR r2,r0,#1  \n\t" // 論理右シフト(１ビット分)
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    "MOV %[Rd2],r2 \n\t" // 変数rd2 ← r2
    : [Rd0] "=r" (rd0) ,[Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2");

  printf("r0 = %d(0x%08x)\n",rd0, rd0);
  printf("r1 = %d(0x%08x)\n",rd1, rd1);
  printf("r2 = %d(0x%08x)\n",rd2, rd2);
}

/*
 * 正の値を算術シフトする
 */
void arm_arithmetic_shift_1() {
  int32_t rd0,rd1;
  __asm__ (
    "LDR r0,=10    \n\t" // r0レジスタ ← 10
    "ASR r1,r0,#1  \n\t" // 算術右シフト(１ビット分)
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1)
    : 
    : "r0","r1");

  printf("r0 = %d(0x%08x)\n",rd0, rd0);
  printf("r1 = %d(0x%08x)\n",rd1, rd1);
}

/*
 * 負の値を算術シフトする
 */
void arm_arithmetic_shift_2() {
  int32_t rd0,rd1;
  __asm__ (
    "LDR r0,=-10   \n\t" // r0レジスタ ← -10
    "ASR r1,r0,#1  \n\t" // 算術右シフト(1ビット分)
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1)
    : 
    : "r0","r1");

  printf("r0 = %d(0x%08x)\n",rd0, rd0);
  printf("r1 = %d(0x%08x)\n",rd1, rd1);
}

/*
 * 論理シフト
 */
void arm_arithmetic_shift_3() {
  int32_t rd0, rd1,rd2;
  __asm__ (
    "LDR r0,=-10   \n\t" // r0 ← -10  
    "ASR r1,r0,#1  \n\t" // 算術右シフト(１ビット分)
    "LSR r2,r0,#1  \n\t" // 論理右シフト(１ビット分)
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    "MOV %[Rd2],r2 \n\t" // 変数rd2 ← r2
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2");

  printf("r0 = %d(0x%08x)\n",rd0, rd0);
  printf("r1 = %d(0x%08x)\n",rd1, rd1);
  printf("r2 = %d(0x%08x)\n",rd2, rd2);
}

/*
 * ローテートシフト
 */
void arm_rotate_shift_1() {
  int32_t rd0,rd1,rd2,rd3,rd4;
  __asm__ (
    "LDR r0,=10    \n\t" // r0レジスタ ← 10
    "ROR r1,r0,#1  \n\t" //  1ビット 右ローテート
    "ROR r2,r0,#2  \n\t" //  2ビット 右ローテート
    "ROR r3,r0,#30 \n\t" // 30ビット 右ローテート(=2ビット 左ローテート)
    "ROR r4,r0,#31 \n\t" // 31ビット 右ローテート(=1ビット 左ローテート)
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    "MOV %[Rd2],r2 \n\t" // 変数rd2 ← r2
    "MOV %[Rd3],r3 \n\t" // 変数rd3 ← r3
    "MOV %[Rd4],r4 \n\t" // 変数rd4 ← r4
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1),[Rd2] "=r" (rd2) ,[Rd3] "=r" (rd3) ,[Rd4] "=r" (rd4) 
    : 
    : "r0","r1","r2","r3","r4");
  printf("r0 = %d(0x%08x)\n",rd0, rd0);
  printf("r1 = %d(0x%08x)\n",rd1, rd1);
  printf("r2 = %d(0x%08x)\n",rd2, rd2);
  printf("r3 = %d(0x%08x)\n",rd3, rd3);
  printf("r4 = %d(0x%08x)\n",rd4, rd4);
}

/*
 * ローテートシフト
 */
void arm_rotate_shift_2() {
  int32_t rd1,rd2,rd3,rd4,rd5,rd6,rd7,rd8,rd9,rd10;
  __asm__ (
    "      MSR  cpsr_f,#0  \n\t"  // cpsrのフラグフィールドをクリア

    "      LDR   r0,=7     \n\t"  // r0: ビット数をカウントする元の値
    "      LDR   r1,=32    \n\t"  // r1: ループカウンタ(カウントするビット数)
    "      LDR   r2,=0     \n\t"  // r2: カウンタ    
    "LOOP: RRXS  r0,r0     \n\t"  // 右へ１ビットシフト。最下位ビットの値はキャリーフラグに格納
    "      ADDCS r2,r2,#1  \n\t"  // キャリーフラグが立っていれば、カウンタを+1する 
    "      SUBS  r1,r1,#1  \n\t"  // ループカウンタを-1する
    "      BNE   LOOP      \n\t"  // ループカウンタ>0ならばループする
    "      MOV   %[Rd1],r2 \n\t"  // 結果を格納する
    : [Rd1] "=r" (rd1)
    : 
    : "r0","r1","r2");

  printf("r2=%d\n",rd1);  
}

int main() {

  WRAP("ch_detail_shift_1_a", arm_shift_1);
  WRAP("ch_detail_shift_2_a", arm_shift_2);
  WRAP("ch_detail_shift_3_a", arm_shift_3);
  WRAP("ch_detail_shift_4_a", arm_shift_4);
  WRAP("ch_detail_logical_shift_1_a", arm_logical_shift_1);
  WRAP("ch_detail_arithmetic_shift_1_a", arm_arithmetic_shift_1);
  WRAP("ch_detail_arithmetic_shift_2_a", arm_arithmetic_shift_2);
  WRAP("ch_detail_arithmetic_shift_3_a", arm_arithmetic_shift_3);
  WRAP("ch_detail_rotate_shift_1_a", arm_rotate_shift_1);
  WRAP("ch_detail_rotate_shift_2_a", arm_rotate_shift_2);

  return 0;
}

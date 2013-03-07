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
    "MOV r0,#5    \n\t" // r0 ← 5 
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
/////end
/////begin ch_detail_shift_2
/*
 * シフト命令を使って16倍する
 */
void arm_shift_2(void) {
  uint32_t d;
  __asm__ (
    "MOV r0,#5    \n\t" // r0 ← 5 
    "LSL r0,r0,#4 \n\t" // r0 ← r0を4ビット左シフト
    "MOV %[Rd],r0 \n\t" // 変数rd ← r0
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
    "MOV r0,#5     \n\t" // r0 ← 5 
    "LSL r1,r0,#1  \n\t" // r1 ← r0 * 2 
    "LSL r2,r0,#2  \n\t" // r2 ← r0 * 4
    "ADD r3,r1,r2  \n\t" // r3 ← r0 * 5
    "ADD r3,r3,r0  \n\t" // r3 ← r0 * 7 = (r0 * 5) + (r0 * 2)
    "MOV %[Rd0],r3 \n\t" // 変数rd0 ← r3
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
    "MOV r0,#5     \n\t" // r0 ← 5 
    "LSL r1,r0,#3  \n\t" 
    "SUB r2,r1,r0  \n\t" 
    "MOV %[Rd0],r2 \n\t" // 変数rd0 ← r2
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
  int32_t rd0,rd1,rd2;
  __asm__ (
    "LDR r0,=10    \n\t" // r0 ← 10 
    "LSL r1,r0,#1  \n\t" // 
    "LSR r2,r0,#1  \n\t" // 
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    "MOV %[Rd2],r2 \n\t" // 変数rd2 ← r2
    : [Rd0] "=r" (rd0) ,[Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2");

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
  int32_t rd0, rd1,rd2;
  __asm__ (
    "LDR r0,=-10   \n\t" // r0 ← -10  
    "LSL r1,r0,#1  \n\t" //
    "LSR r2,r0,#1  \n\t" //
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
    "MOV %[Rd2],r2 \n\t" // 変数rd2 ← r2
    : [Rd0] "=r" (rd0),[Rd1] "=r" (rd1),[Rd2] "=r" (rd2)
    : 
    : "r0","r1","r2");

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
  int32_t rd0,rd1;
  __asm__ (
    "LDR r0,=10    \n\t" // r0レジスタ ← 10
    "ASR r1,r0,#1  \n\t" //
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
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
  int32_t rd0,rd1;
  __asm__ (
    "LDR r0,=-10   \n\t" // r0レジスタ ← -10
    "ASR r1,r0,#1  \n\t" // 
    "MOV %[Rd0],r0 \n\t" // 変数rd0 ← r0
    "MOV %[Rd1],r1 \n\t" // 変数rd1 ← r1
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
  int32_t rd0,rd1,rd2,rd3,rd4;
  __asm__ (
    "LDR r0,=10    \n\t" // r0レジスタ ← 10
    "ROR r1,r0,#1  \n\t" //
    "ROR r2,r0,#2  \n\t" //
    "ROR r3,r0,#30 \n\t" //
    "ROR r4,r0,#31 \n\t" //
    "MOV %[Rd1],r1 \n\t" // 変数rd0 ← r1
    "MOV %[Rd2],r2 \n\t" // 変数rd1 ← r2
    "MOV %[Rd3],r3 \n\t" // 変数rd2 ← r3
    "MOV %[Rd4],r4 \n\t" // 変数rd3 ← r4
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
  __asm__ (
    "      MSR  cpsr_f,#0 \n\t"  // フラグをクリア
    ""
    "      LDR r0,=7      \n\t"  // r0: ビット数をカウントする元の値
    "      MOV r1,#32     \n\t"  // r1: ループカウンタ(カウントするビット数)
    "      MOV r2,#0      \n\t"  // r2: カウンタ    
    "LOOP: RRXS r0,r0     \n\t"  // 右へ１ビットシフト。最下位ビットの値はキャリーフラグに格納
    "      ADDCS r2,r2,#1 \n\t"  // キャリーフラグが立っていれば、カウンタを+1する 
    "      SUBS r1,r1,#1  \n\t"  // ループカウンタを-1する
    "      BNE LOOP       \n\t"  // ループカウンタ>0ならばループする
    "      MOV %[Rd1],r2  \n\t"  // 結果を格納する
    : [Rd1] "=r" (rd1)
    : 
    : "r0","r1","r2");

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

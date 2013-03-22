#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/*
 * 無条件分岐命令
 */
/////begin ch_detail_b_1
void arm_b_sample_1() {
  uint32_t d;
  __asm__ (
    "         MOV  r0,#2   \n\t" // r0 ← 2         
    "         B    finish1 \n\t" // finish1に分岐          
    "         MOV  r0,#10  \n\t" // (この命令は実行されない) 
    "finish1: MOV %[Rd],r0 \n\t" // 変数rd ← r0
    : [Rd] "=r" (d) 
    : 
    : "r0");
  printf("r0 = 0x%08X\n",d);
}
/////end
/*
 * 分岐命令（条件設定あり）
 */
/////begin ch_detail_b_2
void arm_b_sample_2() {
  uint32_t d;
  __asm__ (
    "        MOV r0,#2    \n\t" // r0 ← 2         
    "        MOV r1,#1    \n\t" // r1 ← 1          
    "        CMP r0,r1    \n\t" // r0とr1を比較
    "        BEQ next     \n\t" // r0==r1が真ならばラベルnextへ分岐
    "        MOV r2,#10   \n\t" // r2 ← 10          
    "        B   finish   \n\t" // ラベルfinishへ無条件分岐
    "next:   MOV r2,#20   \n\t" // r2 ← 20          
    "finish: MOV %[Rd],r2 \n\t" // 変数rd ← r2

    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2");
  printf("r2 = %d\n",d);
}
/////end
/*
 * リンク付き分岐命令
 */
/////begin ch_detail_bl_1
void arm_bl_sample_1() {
  uint32_t d;
  __asm__ (
    "         MOV  r0,#2   \n\t" // r0 ← 2
    "         BL   subr1   \n\t" // ラベルsubr1をサブルーチン呼び出し
    "         B    finish2 \n\t" // finish2へ無条件ジャンプ
    "subr1:   MOV  r0,#10  \n\t" // r0 ← 10
    "         BX   lr      \n\t" // サブルーチンから戻る
    "finish2: MOV %[Rd],r0 \n\t" // 変数rd ← r0
    : [Rd] "=r" (d)
    : 
    : "r0", "r14");
  printf("r0 = %d\n",d);
}
/////end
int main() {

  WRAP("ch_detail_b_1_a",arm_b_sample_1);
  WRAP("ch_detail_b_2_a",arm_b_sample_2);
  WRAP("ch_detail_bl_1_a",arm_bl_sample_1);

  return 0;
}

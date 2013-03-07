#include <stdio.h>
#include <stdint.h>
#include "../wrap.h"

/////begin ch_detail_b_1
/*
 * 無条件分岐命令
 */
void arm_b_sample_1() {
  uint32_t d;
  __asm__ (
    "         MOV  r0,#2   \n\t" // r0 ← 2         
    "         B    finish1 \n\t" // finish1に分岐          
    "         MOV  r0,#10  \n\t" // (この命令は実行されない) 
    "finish1: MOV %[Rd],r2 \n\t" // 変数rd ← r2
    : [Rd] "=r" (d) 
    : 
    : "r0","r1","r2","r3");
  printf("r2 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_b_2
/*
 * 分岐命令（条件設定あり）
 */
void arm_b_sample_2() {
  uint32_t d;
  __asm__ (
    "        MOV  r0,#2   \n\t" // r0 ← 2         
    "        MOV  r1,#1   \n\t" // r1 ← 1          
    "        CMP  r0,r1   \n\t" // r0とr1を比較
    "        BEQ  next    \n\t" // r0==r1ならばラベルnextへ無条件分岐
    "        MOV  r2,#0   \n\t" // r2 ← 0          
    "        B    finish  \n\t" // ラベルfinishへ無条件分岐
    "next:                \n\t"
    "        MOV r2,#1    \n\t" // r2 ← 1          
    "finish: MOV %[Rd],r2 \n\t" // 変数rd ← r2

    : [Rd] "=r" (d)
    : 
    : "r0","r1","r2");
  printf("r2 = 0x%08X\n",d);
}
/////end
/////begin ch_detail_bl_1
/*
 * リンク付き分岐命令
 */
void arm_bl_sample_1() {
  uint32_t d;
  __asm__ (
    "         MOV  r0,#2   \n\t" // r0 ← 2
    "         BL   subr1   \n\t" // subr1をサブルーチン呼び出し
    "         B    finish2 \n\t" // finish2へ無条件ジャンプ
    "subr1:                \n\t"
    "         MOV  r0,#10  \n\t" // r0 ← 10
    "         BX   lr      \n\t" // サブルーチンから戻る
    "finish2: MOV %[Rd],r0 \n\t" // 変数rd ← r0
    : [Rd] "=r" (d)
    : 
    : "r0", "r14");
  printf("r0 = 0x%08X\n",d);
}
/////end


int main() {

  WRAP("ch_detail_b_1_a",arm_b_sample_1);
  WRAP("ch_detail_b_2_a",arm_b_sample_2);
  WRAP("ch_detail_bl_1_a",arm_bl_sample_1);

  return 0;
}

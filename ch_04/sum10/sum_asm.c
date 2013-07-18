#include <stdio.h>

int sum(int limit)
{
   int i,total=0;
   __asm__ (
     "      MOV  r0,#0      \n\t"  // (1) int total = 0;
     "      MOV  r1,%[Rs1]  \n\t"  // (2) int i = limit;
     "loop:                 \n\t"  // (3)
     "      ADD  r0, r0, r1 \n\t"  // (4) total = total + i;
     "      SUBS r1, r1, #1 \n\t"  // (5) i=i-1(演算結果をcpsrレジスタに反映)
     "      BGT  loop       \n\t"  // (6) if (i > 0) goto loop;
     "      MOV  %[Rd],r0"         // (7) r0レジスタの値(結果となる値)をC言語の変数に格納する
    : [Rd] "=r" (total) 
    : [Rs1] "r" (limit)
    );
   return total;
}

int main()
{
   int val = 10;
   int retval = sum(val);
  printf("sum(%d) = %d\n",val,retval);
  return 0;
}

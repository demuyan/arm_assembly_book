#include <stdio.h>

int sum(int val)
{
   int i,total=0;
   __asm__ (
     "      MOV r0,#0\n\t"
     "      MOV r1,%[Rs1]\n\t"
     "loop: ADD r0, r0, r1\n\t"
     "      SUBS r1, r1, #1\n\t"
     "      BGE loop\n\t"
     "      MOV %[Rd],r0"
    : [Rd] "=r" (total) 
    : [Rs1] "r" (val)
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

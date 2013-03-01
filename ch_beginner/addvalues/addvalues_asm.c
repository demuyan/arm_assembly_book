#include <stdio.h>
#include <stdint.h>

int addvalues(int a, int b)
{
  int c;

  __asm__ (
    "ADD %[Rd],%[Rs1],%[Rs2]"
    : [Rd] "=r" (c) 
    : [Rs1] "r" (a), [Rs2] "r" (b)
    );

  return c;
}

int main()
{
  int val = addvalues(1,2);
  printf("addvalues = %d\n",val);
  return 0;
}

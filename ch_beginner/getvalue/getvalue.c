#include <stdio.h>

int get_value()
{
  int c = 1;
  return c;
}

int main()
{
  int val = get_value();
  printf("get_value = %d\n",val);
  return 0;
}

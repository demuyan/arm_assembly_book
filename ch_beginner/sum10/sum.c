#include <stdio.h>

int sum(int val){
  int i,total=0;

  for (i = 0; i <= val; i++){
	total += i;
  }

  return total;
}

int sum_1(int val){
  int i = val,total=0;

  do {
    total += i;
    i=i-1;
  } while(i > 0);

  return total;
}

int sum_2(int val){
  int i = val,total=0;

loop:
  total += i;
  i=i-1;
  if (i > 0) goto loop;

  return total;
}



int main(){
  int val = 10;
  printf("sum(%d) = %d\n",val,sum(val));
  printf("sum_1(%d) = %d\n",val,sum_1(val));
  printf("sum_2(%d) = %d\n",val,sum_2(val));
  return 0;
}

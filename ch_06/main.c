#include <stdio.h>
#include <stdint.h>
#include "add_values.h"
#include "simple_struct.h"

int main() {

  uint32_t val1 = 1,  val2 = 2, val3 = 3, val4 = 4, val5 = 5, val6=6;
  
  /* 2つの引数値の合計を返す */
  uint32_t retval2 = add_values(val1, val2);
  printf("add_values()=%d\n",retval2);

  /* 6つの引数値の合計を返す */
  uint32_t retval6 = add_values6(val1, val2, val3, val4, val5, val6);
  printf("add_values6()=%d\n",retval6);

  /* メンバー変数の値の合計を返す */ 
  simple_struct dat;
  dat.val_int = 1;
  dat.val_short = 2;
  dat.val_char = 3;

   int struct_size = sizeof(simple_struct);

//  printf("val_int*=%p\n",&dat.val_int);
//  printf("val_short*=%p\n",&dat.val_short);
//  printf("val_char*=%p\n",&dat.val_char);

//  printf("struct_size=%d\n",struct_size);

  uint32_t retval_dat = sum_struct_values(&dat);
  printf("sum_struct_values()=%d\n",retval_dat);

  return 0;
}

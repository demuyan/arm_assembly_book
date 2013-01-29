#include <stdio.h>
#include <stdint.h>
#include "simple_struct.h"

/*
 * メンバー変数の値の合計値を返す
 */
uint32_t sum_struct_values(simple_struct *dat){
  return dat->val_int+dat->val_short+dat->val_char;
}

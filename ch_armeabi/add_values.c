#include <stdio.h>
#include <stdint.h>
/////begin ch_armeabi_sample1
/*
 * 2つの引数値の合計を算出
 */
uint32_t add_values(uint32_t a, uint32_t b){
  return a+b;
}
/////end
/////begin ch_armeabi_sample2
/*
 * 6つの引数値の合計を算出
 */
uint32_t add_values6(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f){
  return a+b+c+d+e+f;
}
/////end

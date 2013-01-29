#include <stdio.h>
#include <stdint.h>

extern uint32_t add_vals(uint32_t a, uint32_t b);

int main() {

  uint32_t val1 = 1,  val2 = 2;
  uint32_t retval = add_vals(val1, val2);

  printf("retval=%d\n",retval);

  return 0;
}

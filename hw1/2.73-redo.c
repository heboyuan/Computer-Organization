#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y){
  int result = x + y;
  int pos_over = -(result < 0);
  int over = -(__builtin_add_overflow_p(x, y, (__typeof__((x) + (y))) 0));
  int MAX = (pos_over & INT_MAX) | (~pos_over & INT_MIN);
  return (over & MAX )| (~over & result);
}

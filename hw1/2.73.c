#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y){
  int result = x + y;
  int pos_over = -(result < 0);
  int shift = ((sizeof(int)<<3)-1);
  int sx = x >> shift;
  int sy = y >> shift;
  int sr = result >> shift;
  int over = -((sx == sy) && (sx != sr));
  int MAX = (pos_over & INT_MAX) | (~pos_over & INT_MIN);
  return (over & MAX )| (~over & result);
}

int main(void){
  printf("%d\n", saturating_add(2435, 3425) == (2435 + 3425));

  printf("%d\n", saturating_add(INT_MAX, 1000000000));
  printf("%d\n", INT_MAX);
  printf("\n");

  printf("%d\n", saturating_add(INT_MAX, 1));
  printf("%d\n", INT_MAX);
  printf("\n");

  printf("%d\n", saturating_add(INT_MAX-1000000000, 1000000000));
  printf("%d\n", INT_MAX);
  printf("\n");

  printf("%d\n", saturating_add(INT_MIN, -1));
  printf("%d\n", INT_MIN);
  printf("\n");

  printf("%d\n", saturating_add(INT_MIN+1000000000, -1000000001));
  printf("%d\n", INT_MIN);
  printf("\n");

  printf("%d\n", saturating_add(INT_MIN, -1000000000));
  printf("%d\n", INT_MIN);
  return 1;
}

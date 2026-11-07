
#include <stdio.h>

int main(void) {
  int x;
  int y;

  x = 6;
  y = ++x + 2;  // y is assigned 9: increment x first, then evaluate x + 2 (9)
  printf("x is %d\n", y);

  x = 6;
  y = x++ + 2;
  printf("x is %d\n", y); // y is assigned 8: evaluate x + 2 first (8), then increment x
  return 0;
}

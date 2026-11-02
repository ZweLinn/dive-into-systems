
#include <stdio.h>

int main(void) {
  /* 1. Define variables in this block's scope at the top of the block. */
  int x;
  int i, j, k;
  char letter;
  float winpct;
  double pi;

  x = 7;
  k = x + 2;
  letter = 'H'; // a single quote is used for single character value
  letter = letter + 1;

  pi = 3.1415926;

  winpct = 11 / 2.0;
  j = 11 / 2;
  x = k % 2;

  printf("%d\n" , letter);
  return 0;
};

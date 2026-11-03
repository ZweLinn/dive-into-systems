// C supports for and while loops.

#include <stdio.h>

int main(void) {
  printf("hello\n");

  // while
  int num, val;
  if (num < 0) {
    num = -num;
  }
  printf("num is :%d\n ", num);
  val = 1;
  while (val < num) {
    val = val * 2;
    printf("val is now: %d\n", val);
  }

  // for
  int num1, i;

  printf("Enter a value: ");
  scanf("%d", &num1);

  for (i=0 ; i <= num1 ; i++) {
      printf("%d\n" , i);
  }
  return 0;
}

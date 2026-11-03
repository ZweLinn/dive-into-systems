// C doesn’t provide a Boolean type with true or false values.

#include <stdbool.h> // For boolean data type (bool, true, false)
#include <stdio.h>
int main(void) {
  printf("hello\n");

  int num1, num2;
  num1 = 1;
  num2 = 4;

  _Bool x = num1 == num2;

  printf("x is %b\n", x);

  bool isTrue = true;
  bool isFalse = false;

  bool negativeInt= -3; //nonzero (any positive or negative value) evaluates to true


  printf("True : %d\n", isTrue);
  printf("False : %d\n", isFalse);
  printf("Negative : %d\n", negativeInt);
  return 0;
}

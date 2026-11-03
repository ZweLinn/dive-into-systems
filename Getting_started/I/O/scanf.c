//C’s scanf function represents one method
// for reading in values entered by the user (via the keyboard) and storing them in program variables.

#include <stdio.h>

int main(void) {
  printf("hello\n");

  int num1 , num2;

  printf("Enter a number: ");
  scanf("%d" , &num1);

  printf("Enter a number: ");
  scanf("%d" , &num2);
  printf("%d + %d = %d\n", num1, num2, (num1+num2));

  int x;
  float pi;

  // read in an int value followed by a float value ("%d%g")
  // store the int value at the memory location of x (&x)
  // store the float value at the memory location of pi (&pi)
  scanf("%d%g", &x, &pi);
  printf("%d%g" , x , pi);
  return 0;
};

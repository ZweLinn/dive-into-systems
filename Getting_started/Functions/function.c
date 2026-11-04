// function definition format:
// ---------------------------
//<return type> <function name> (<parameter list>)
//{
//   <function body>
//}

// parameter list format:
// ---------------------
//<type> <param1 name>, <type> <param2 name>, ...,  <type> <last param name>

#include <stdio.h>
int max(int num1, int num2) {
  int bigger;
  bigger = num1;
  if (num1 > num2) {
    bigger = num2;
  }
  printf("  in max, before return x: %d y: %d\n", num1, num2);
  return bigger;
};

// Functions that don’t return a value should specify the void return type.

void printHello() { printf("hello\n"); }

int main(void) {

  printHello();
  max(3, 4);

  return 0;
}

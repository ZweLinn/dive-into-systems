#include <stdio.h>

int main(void) {

  // First, declare a pointer variable using type_name *var_name:

  int *ptr;   // stores the memory address of an int (ptr "points to" an int)
  char *cptr; // stores the memory address of a char (cptr "points to" a char)

  int x;
  char ch;

  // Next, initialize the pointer variable

  ptr = &x;   // ptr gets the address of x, pointer "points to" x
  cptr = &ch; // cptr gets the address of ch, pointer "points to" ch

  x = 8;
  printf("Value of ptr is : %d\n", *ptr); // out put is 8

  *ptr = 11;
  printf("Value of x is : %d\n", x); // out put is 11

  ch = 'H';
  printf("Value of cptr is : %c\n", *cptr); // out put is H

  // Null
  int *ptr1, *ptr2;

  ptr2 = &x;
  ptr1 = NULL;


  printf("Value of ptr2 is : %d\n", *ptr2); // out put is 11

  *ptr1 = 6;    // CRASH! program crashes with a segfault (a memory fault)

  //ptr1 = 20;
 // *ptr1 = 6;    // CRASH! segfault (20 is not a valid address)

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *p;
  p = malloc(sizeof(int)); // allocate heap memory for storing an int



  if (p != NULL) {  //If allocation fail will NULL, so need to add NULL check
    *p = 6; // the heap memory p points to gets the value 6
  };

  // if (p == NULL) {
  //     printf("Bad malloc error\n");
  //     exit(1);   // exit the program and indicate error
  // }



  printf("Value of p is : %d\n", *p);
  free(p); // no longer need heap memory it dynamically allocated with malloc, use with free()
  p=NULL;

  // for checking size of the allocated block
  size_t n = sizeof(int) + 3;
  p = malloc(n);
  printf("allocated bytes: %zu\n", n);


  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *p;
  p = malloc(sizeof(int) + 3); //

  if (p != NULL) {
    *p = 6; // the heap memory p points to gets the value 6
  };

  printf("Value of p is : %d\n", *p);
  free(p);

  // for checking size of the allocated block
  size_t n = sizeof(int) + 3;
  p = malloc(n);
  printf("allocated bytes: %zu\n", n);


  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int i;
  int s_array[20]; // static
  int *d_array;    // dynamic

  d_array = malloc(sizeof(int) * 20);
  if (d_array == NULL) {
    printf("Error: malloc failed\n");
    exit(1);
  }
  
  // Heap buffer overflow: malloc(): corrupted top size
  for (i = 0; i < 125; i++) {
    d_array[i] = i;
  }
  printf("%d \n", d_array[100]); // crashes here
  // malloc(): corrupted top size
  // Aborted (core dumped)

  return 0;
}

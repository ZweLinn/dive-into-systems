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

  for (i = 0; i < 20; i++) {
    s_array[i] = i;
    d_array[i] = i;
  }

  printf("%d %d \n", s_array[3], d_array[3]); // output 3 3

  // Heap buffer overflow: malloc(): corrupted top size
  for (i = 0; i < 125; i++) {
    d_array[i] = i;
  }
  printf("%d \n", d_array[100]); // crashes here
  // malloc(): corrupted top size
  // Aborted (core dumped)

  return 0;
}

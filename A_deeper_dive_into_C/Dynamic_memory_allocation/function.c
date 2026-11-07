#include <stdio.h>
#include <stdlib.h>
void init_arr(int *arr, int size);

int main(void) {
  int *arr1;
  int size = 10;

  arr1 = malloc(sizeof(int) * size);

  if (arr1 == NULL) {
    printf("malloc error\n");
    exit(1);
  }
  /* pass the value of arr1 (base address of array in heap) */
  init_arr(arr1, 10);

  printf("3rd index of arr1 is : %d\n" , arr1[3]);
  return 0;
}

void init_arr(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    arr[i] = i;
  }
}

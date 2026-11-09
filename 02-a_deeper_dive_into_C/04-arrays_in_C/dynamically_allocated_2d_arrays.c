#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 4

int main(void) {
  int i, j;

  // Method 1: Memory-Efficient Allocation
  int *two_d_array;
  two_d_array = malloc(sizeof(int) * N * M);
  if (two_d_array == NULL) {
    printf("ERROR: malloc failed!\n");
    exit(1);
  }

  // fill the array
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      two_d_array[i * M + j] = i + j;
    }
  }

  // print as a table
  printf("      ");
  for (j = 0; j < M; j++) {
    printf("col%d ", j); // column header
  }
  printf("\n");

  for (i = 0; i < N; i++) {
    printf("row%d |", i); // row label
    for (j = 0; j < M; j++) {
      printf("%4d ", two_d_array[i * M + j]); // %4d keeps columns aligned
    }
    printf("\n"); // new line after each row
  }

  free(two_d_array); // release heap memory
  return 0;
}

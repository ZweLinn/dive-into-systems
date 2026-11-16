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
  printf("Method one\n");
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
  two_d_array = NULL;



  //-----------------------------------------------------------------------------------------------------------
  // Method 2: The Programmer-Friendly Way


  int **two_d_array2;
  two_d_array2 =
      malloc(sizeof(int *) * N); // allocate an array of N pointers to ints

  for (i = 0; i < N; i++) {
    // malloc space for row i's M column elements
    two_d_array2[i] = malloc(sizeof(int) * M);
  }
  for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
          two_d_array2[i][j] = i + j;
      }
  }

  printf("Method Two\n");
  for (i = 0; i < N; i++) {
    printf("row%d |", i); // row label
    for (j = 0; j < M; j++) {
      printf("%4d ", two_d_array2[i][j]); // %4d keeps columns aligned
    }
    printf("\n");
  }


  return 0;
}

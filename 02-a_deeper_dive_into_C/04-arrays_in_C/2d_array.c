#include <stdio.h>

int main(void) {

    //Statically Allocated 2D Arrays

    int   matrix[50][100];
    short little[10][10];

    matrix[2][3] = 8;
    matrix[49][99] = 13;


    printf("value of matrix[2][3] is %d\n" , matrix[2][3]);
    printf("value of matrix[49][99] is %d\n" , matrix[49][99]);

    int i, j;

    for (i = 0; i < 50; i++) {  // for each row i
        for (j = 0; j < 100; j++) { // iterate over each column element in row i
            matrix[i][j] = 3;
        }
    }

    printf("value of matrix[4][59] is %d\n" , matrix[4][59]);

  return 0;
}

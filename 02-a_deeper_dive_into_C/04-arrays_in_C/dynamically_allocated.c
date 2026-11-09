#include <stdlib.h>
#include <stdio.h>
int main(void) {

    int *p_array;
    double *d_array;
    int i;
    p_array = malloc(sizeof(int) * 50);
    d_array = malloc(sizeof(double) *06);

    if( (p_array == NULL) || (d_array ==NULL)){
        printf("ERROR : malloc filed \n");
        exit(1);
    }

    for (i = 0; i < 50; i++) {
        p_array[i] = 0;
        d_array[i] = 0.0;
    }

    free(p_array);
    p_array = NULL;

    free(d_array);
    d_array = NULL;

  return 0;
}

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;   // save the value that a points to
    *a = *b;         // put b's value into a's location
    *b = temp;       // put the saved value into b's location
}

int main() {
    int x = 3, y = 7;
    swap(&x, &y);
    printf("%d %d\n", x, y);   //Output is 7 3
    return 0;
}

#include <stdio.h>

void add_one(int n) {
    n = n + 1;
}

int main() {
    int x = 5;
    add_one(x);
    printf("%d\n", x);   // Output is 5 (not 6)
    return 0;
}

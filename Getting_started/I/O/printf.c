// C’s printf function is very similar to formatted print in Python
#include <stdio.h> // needed for printf

int main(void) {

    printf("Name: %s,  Info:\n", "Vijay");
    printf("\tAge: %d \t Ht: %g\n",20,5.9);
    printf("\tYear: %d \t Dorm: %s\n",
            3,"Alice Paul");

    // %g:  placeholder for a float (or double) value
    // %d:  placeholder for a decimal value (int, short, char)
    // %s:  placeholder for a string value

    char ch;

    ch = 'A';
    printf("ch value is %d which is the ASCII value of  %c\n", ch, ch);
    return 0;
}

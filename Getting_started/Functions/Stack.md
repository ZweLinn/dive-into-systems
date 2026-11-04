# The Stack
(Stack is the place in memory where your local variables and function arguments go.)
**The execution stack keeps track of the state of active functions in a program.**

Each function call creates a new stack frame (sometimes called an activation frame or activation record) containing its parameter and local variable values.


The image shows a call stack with two stack frames. The `max` frame sits on top of the `main` frame.

## Stack

### `max` frame

| Variable | Value |
|----------|-------|
| `x`      | **100** |
| `y`      | 100 |
| `bigger` | 100 |

### `main` frame

| Variable | Value |
|----------|-------|
| `a`      | 13 |
| `b`      | 100 |
| `res`    | ? |

## Text-based sketch

```
        ┌─────────────────────┐
 max:   │  x:       [ 100 ]   │
        │  y:       [ 100 ]   │
        │  bigger:  [ 100 ]   │
        ├─────────────────────┤
 main:  │  a:       [  13 ]   │
        │  b:       [ 100 ]   │
        │  res:     [  ?  ]   │
        └─────────────────────┘
                Stack
```
```/* This file shows examples of defining and calling C functions.
 * It also demonstrates using scanf().
 */

#include <stdio.h>

/* This is an example of a FUNCTION PROTOTYPE.  It declares just the type
 * information for a function (the function's name, return type, and parameter
 * list). A prototype is used when code in main wants to call the function
 * before its full definition appears in the file.
 */
int max(int n1, int n2);

/* A prototype for another function.  void is the return type of a function
 * that does not return a value
 */
void print_table(int start, int stop);

/* All C programs must have a main function.  This function defines what the
 * program does when it begins executing, and it's typically used to organize
 * the big-picture behavior of the program.
 */
int main(void) {
    int x, y, larger;

    printf("This program will operate over two int values.\n");

    printf("Enter the first value: ");
    scanf("%d", &x);

    printf("Enter the second value: ");
    scanf("%d", &y);

    larger = max(x, y);

    printf("The larger of %d and %d is %d\n", x, y, larger);

    print_table(x, larger);

    return 0;
}

/* This is an example of a FUNCTION DEFINITION.  It specifies not only the
 * function name and type, but it also fully defines the code of its body.
 * (Notice, and emulate, the complete function comment!)
 */
/* Computes the max of two integer values.
 *   n1: the first value
 *   n2: the other value
 *   returns: the larger of n1 and n2
 */
int max(int n1, int n2)  {
    int result;

    result = n1;

    if (n2 > n1) {
        result = n2;
    }

    return result;
}

/* prints out the squares from start to stop
 *   start: the beginning of the range
 *   stop: the end of the range
 */
void print_table(int start, int stop) {
    int i;

    for (i = start; i <= stop; i++) {
        printf("%d\t", i*i);
    }

    printf("\n");
}
```

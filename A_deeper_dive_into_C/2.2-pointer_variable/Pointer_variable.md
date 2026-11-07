# C’s Pointer Variables

*C’s pointer variables provide a level of indirection to accessing program memory.*
For example, through pointer variables, a C programmer can:

- implement functions whose parameters can modify values in the caller’s stack frame

-dynamically allocate (and deallocate) program memory at runtime when the program needs it

- efficiently pass large data structures to functions

- create linked dynamic data structures

- interpret bytes of program memory in different ways.

## Pointer Variables

*A pointer variable stores the address of a memory location in which a value of a specific type can be stored.*

For example, a pointer variable can store the value of an int address at which the integer value 12 is stored. The pointer variable points to (refers to) the value. 

```
        ┌──────┐          ┌──────┐
ptr:    │      │ ───────► │  12  │
        └──────┘          └──────┘
```

C programs most frequently use pointer variables for:

1. "Pass by pointer" parameters, for writing functions that can modify their argument’s value through a pointer parameter

2. Dynamic memory allocation, for writing programs that allocate (and free) space as the program runs. Dynamic memory is commonly used for dynamically allocating arrays. It is useful when a programmer doesn’t know the size of a data structure at compile time (e.g., the array size depends on user input at runtime). It also enables data structures to be resized as the program runs.


### Pass by pointer

When you give a function an argument in C, the function gets a copy of the value. This is called “pass by value.”

- [Pass by value](pass_by_value.c)

Pass by pointer is like giving someone the address of your house. They can go there and change your original paper.

- [Pass by pointer](pass_by_pointer.c)

### Dynamic Allocation

The problem: you often don’t know the array size in advance

A normal array needs a fixed size when you write the code (at compile time).

```
int arr[100];   // exactly 100 items
```

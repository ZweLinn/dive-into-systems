# Dynamic Memory Allocation

Dynamic memory allocation allows a C program to request more memory as it’s running, and a pointer variable stores the address of the dynamically allocated space.

Dynamic memory allocation grants flexibility to programs that:

- do not know the size of arrays or other data structures until runtime (e.g. the size depends on user input)

- need to allow for a variety of input sizes (not just up to some fixed capacity)

- want to allocate exactly the size of data structures needed for a particular execution (don’t waste capacity)

- grow or shrink the sizes of memory allocated as the program runs, reallocating more space when needed and freeing up space when it’s no longer required.

Dynamically allocated memory occupies the heap memory region of a program’s address space.

## Heap Memory

Everything the program needs to run is in its memory space, and different types of entities reside in different parts of a program’s memory space. For example, the code region contains the program’s instructions, global variables reside in the data region, local variables and parameters occupy the stack, and dynamically allocated memory comes from the heap.

**When a program dynamically requests memory at runtime, the heap provides a chunk of memory whose address must be assigned to a pointer variable.**

```text
            Parts of Program Memory

  0:  ┌──────────────────────────────────────┐
  1:  │           Operating system           │
  …   ├──────────────────────────────────────┤
      │               Code                   │
  M   ├──────────────────────────────────────┤
  e   │               Data                   │
  m   ├──────────────────────────────────────┤
  o   │               Heap                   │
  r   │                          ┌───┐       │
  y   │                          │ 6 │ ◄─────┼──┐
      ├──────────────────────────┴───┴───────┤  │
  a   │                 │                    │  │
  d   │                 ▼  heap grows down    │  │
  d   │                                      │  │
  r   │                                      │  │
  e   │                 ▲  stack grows up     │  │
  s   │                 │                    │  │
  s   ├──────────────────────────────────────┤  │
  e   │              Stack:                  │  │
  s   │                          ptr: ┌───┐  │  │
      │                               │ ●─┼──┼──┘
 max: │                               └───┘  │
      └──────────────────────────────────────┘
```

_It’s important to remember that heap memory is anonymous memory, where "anonymous" means that addresses in the heap are not bound to variable names._

## malloc and free

malloc and free are functions in the standard C library (stdlib) that a program can call to allocate and deallocate memory in the heap. Heap memory must be explicitly allocated (malloc’ed) and deallocated (freed) by a C program

- [malloc and free](malloc_&_free.c)

## Dynamically Allocated Arrays and Strings

C programmers often dynamically allocate memory to store arrays.
To dynamically allocate space for an array of elements, pass malloc the total number of bytes in the desired array.

```
  int *arr;
  char *c_arr;
  // allocate an array of 20 ints on the heap:
  arr = malloc(sizeof(int) * 20);

  // allocate an array of 10 chars on the heap:
  c_arr = malloc(sizeof(char) * 10);
```

```text
 main:
┌───────────────────────────┐        ┌─────────────────────────────────────────────┐
│                           │        │      0   1   2        ...       19          │
│       ┌────────────┐      │        │    ┌───┬───┬───┬───────────────┬───┐        │
│   arr:│addr in heap├──────┼────────┼───►│   │   │   │               │   │        │
│       └────────────┘      │        │    └───┴───┴───┴───────────────┴───┘        │
│                           │        │                                             │
│                           │        │      0   1   2   ...   9                    │
│       ┌────────────┐      │        │    ┌───┬───┬───┬─────┬───┐                  │
│ c_arr:│addr in heap├──────┼────────┼───►│   │   │   │     │   │                  │
│       └────────────┘      │        │    └───┴───┴───┴─────┴───┘                  │
│                           │        │                                             │
└───────────────────────────┘        └─────────────────────────────────────────────┘
           Stack                                          Heap

    A 20-element integer array and 10-element character array allocated on the heap.
```

we can use the same syntax to access elements in dynamically allocated arrays as we use to access elements in statically declared arrays.

-[C programmers often dynamically allocate memory to store arrays.](Array_&_String.c)

### Heap buffer overflow

A heap buffer overflow happens when a program writes more data into a heap-allocated block of memory (from malloc, calloc, realloc) than the block was sized to hold. The extra bytes spill into adjacent memory, which is undefined behavior in C.

-[Heap buffer overflow](Heap_buffer_overflow.c)

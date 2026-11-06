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

*It’s important to remember that heap memory is anonymous memory, where "anonymous" means that addresses in the heap are not bound to variable names.*

## malloc and free

malloc and free are functions in the standard C library (stdlib) that a program can call to allocate and deallocate memory in the heap. Heap memory must be explicitly allocated (malloc’ed) and deallocated (freed) by a C program

- [malloc and free](malloc_&_free.c)

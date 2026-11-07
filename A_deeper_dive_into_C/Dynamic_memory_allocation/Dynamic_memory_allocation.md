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

Why it’s a problem

The heap holds other allocations and also allocator bookkeeping (metadata such as chunk sizes and free-list pointers). Overflowing can:

- Corrupt other data in neighboring allocations, causing strange bugs far from the actual mistake.
- Crash the program, often later (for example, inside free() or a subsequent malloc()), which makes it hard to debug.
- Corrupt allocator metadata, leading to heap corruption.
- Become a security vulnerability. Attackers can sometimes use an overflow to alter program behavior or achieve code execution, which is why these bugs show up so often in CVEs.

-[Heap buffer overflow](Heap_buffer_overflow.c)

The C standard library implements malloc and free, which are the programming interface to its heap memory manager. When called, malloc needs to find a contiguous chunk of unallocated heap memory space that can satisfy the size of the request. The heap memory manager maintains a free list of unallocated extents of heap memory, where each extent specifies the start address and size of a contiguous unallocated chunk of heap space.

Initially, all of heap memory is empty, meaning that the free list has a single extent consisting of the entire heap region. After a program has made some calls to malloc and free, heap memory can become fragmented, meaning that there are chunks of free heap space interspersed with chunks of allocated heap space. The heap memory manager typically keeps lists of different ranges of sizes of heap space to enable fast searching for a free extent of a particular size. In addition, it implements one or more policies for choosing among multiple free extents that could be used to satisfy a request.

The free function may seem odd in that it only expects to receive the address of the heap space to free without needing the size of the heap space to free at that address. That’s because malloc not only allocates the requested memory bytes, but it also allocates a few additional bytes right before the allocated chunk to store a header structure. The header stores metadata about the allocated chunk of heap space, such as the size. As a result, a call to free only needs to pass the address of heap memory to free. The implementation of free can get the size of the memory to free from the header information that is in memory right before the address passed to free.

### Pointers to Heap Memory and Functions

When passing a dynamically allocated array to a function, the pointer variable argument’s value is passed to the function (i.e., the base address of the array in the heap is passed to the function).Thus, when passing either statically declared or dynamically allocated arrays to functions, the parameter gets exactly the same value — the base address of the array in memory.

```
int main(void) {
    int *arr1;

    arr1 = malloc(sizeof(int) * 10);
    if (arr1 == NULL) {
        printf("malloc error\n");
        exit(1);
    }

    /* pass the value of arr1 (base address of array in heap) */
    init_array(arr1, 10);
    ...
}

void init_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = i;
    }
}
```

```text
            ┌──────────────────────────────┐
init_array: │        ┌────┐     ┌────┐     │
            │  size: │ 10 │  i: │ 10 │     │              ┌──────────────────────────────────┐
            │        └────┘     └────┘     │              │                                  │
            │                              │              │      0   1   2     ...    9      │
            │        ┌──────────────┐      │              │    ┌───┬───┬───┬────────┬───┐    │
            │   arr: │ addr in heap │──────├──────┬───────┼───►│ 0 │ 1 │ 2 │  ...   │ 9 │    │
            │        └──────────────┘      │      │       │    └───┴───┴───┴────────┴───┘    │
            ├──────────────────────────────┤      │       │                                  │
main:       │                              │      │       │                                  │
            │        ┌──────────────┐      │      │       │                                  │
            │  arr1: │ addr in heap │──────├──────┘       │                                  │
            │        └──────────────┘      │              │                                  │
            │                              │              │                                  │
            └──────────────────────────────┘              └──────────────────────────────────┘
                          Stack                                          Heap
        The contents of memory prior to returning from init_array. Both main’s arr1 and init_array’s arr variable point to the same block of heap memory.
```

-[Heap Memory and Functions](function.c)

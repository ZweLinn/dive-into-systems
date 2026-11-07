Declaring a variable outside of any function body creates a global variable. Global variables remain permanently in scope and can be used by any code in the program because they’re always bound to one specific memory location.

Local variables and parameters are only in scope inside the function in which they are defined.

*While there may occasionally be times when using global variables in C programs is necessary, we strongly recommend that you avoid programming with global variables whenever possible.*

*sing only local variables and parameters yields code that’s more modular, more general-purpose, and easier to debug.*

# A program’s memory space

A program’s address space (or memory space) represents storage locations for everything it needs in its execution, namely storage for its instructions and data.

# Parts of Program Memory

Memory addresses run from `0:` at the top to `max:` at the bottom.

| Address | Region | Contents |
|---------|--------|----------|
| `0:`, `1:`, `…` | **Operating system** | Reserved for the operating system |
| | **Code** | Function instructions stored here |
| | **Data** | Global variables stored here |
| | **Heap** | Dynamically allocated memory. Grows as program allocates memory |
| | *(free space)* | The heap grows downward (↓) and the stack grows upward (↑) into this gap |
| `max:` | **Stack** | Local variables and parameters stored here. Grows as program calls functions. Shrinks on return from function |

## Regions (top to bottom)

- **Operating system**
- **Code:** function instructions stored here
- **Data:** global variables stored here
- **Heap:** dynamically allocated memory; grows as program allocates memory
- *(blue arrow pointing down, green arrow pointing up: the heap and stack grow toward each other)*
- **Stack:** local variables and parameters stored here; grows as program calls functions; shrinks on return from function

Local variables and parameters reside in the portion of memory for the stack. Because the amount of stack space grows and shrinks over the program’s execution as functions are called and returned from, the stack part of memory is typically allocated near the bottom of memory (at the highest memory addresses) to leave space for it to change.

Global variables are stored in the data section. Unlike the stack, the data region does not grow or shrink — storage space for globals persists for the entire run of the program.

*The heap portion of memory is the part of a program’s address space associated with dynamic memory allocation. The heap is typically located far from stack memory, and grows into higher addresses as more space is dynamically allocated by the running program.*

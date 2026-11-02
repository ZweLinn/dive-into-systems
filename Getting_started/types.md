# Types
8     // the int value 8
3.4   // the double value 3.4
'h'   // the char value 'h' (its value is 104, the ASCII value of h)

## char
**The C char type stores a numeric value. C doesn’t support a string type,**
**but programmers can create strings from the char type and C’s support for constructing arrays of values**

'h'  // this is a char literal value   (its value is 104, the ASCII value of h)
"h"  // this is a string literal value (its value is NOT 104, it is not a char)

## numeric

| Type name   | Usual size  | Values stored            | How to declare |
| ----------- | ----------- | ------------------------ | -------------- |
| `char`      | 1 byte      | integers                 | `char x;`      |
| `short`     | 2 bytes     | signed integers          | `short x;`     |
| `int`       | 4 bytes     | signed integers          | `int x;`       |
| `long`      | 4 or 8 bytes | signed integers         | `long x;`      |
| `long long` | 8 bytes     | signed integers          | `long long x;` |
| `float`     | 4 bytes     | signed real numbers      | `float x;`     |
| `double`    | 8 bytes     | signed real numbers      | `double x;`    |

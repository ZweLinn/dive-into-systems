# one-Dimensional Arrays

## Array Memory Layout
Whether an array is statically declared or dynamically allocated via a single call to malloc, array elements represent contiguous memory locations.

```
array [0]:  base address
array [1]:  next address
array [2]:  next address
  ...            ...
array [99]: last address
```

```
int  iarray[6];  // an array of six ints, each of which is four bytes
char carray[4];  // an array of four chars, each of which is one byte
```

The addresses of their individual array elements might look something like this:
```
addr   element
----   -------
1230:  iarray[0]
1234:  iarray[1]
1238:  iarray[2]
1242:  iarray[3]
1246:  iarray[4]
1250:  iarray[5]
    ...
1280:  carray[0]
1281:  carray[1]
1282:  carray[2]
1283:  carray[3]
```

In this example, 1230 is the base address of iarray and 1280 the base address of carray. Note that individual elements of each array are allocated to contiguous memory addresses: each element of iarray stores a 4-byte int value, so its element addresses differ by 4, and each element of carray stores a 1-byte char value, so its addresses differ by 1. There is no guarantee that the set of local variables are allocated to contiguous memory locations on the stack (hence, there could be a gap in the addresses between the end of iarray and the start of carray, as shown in this example.)


# Two-Dimensional Arrays

# one-Dimensional Arrays

-[One-Dimensional arrays](1d_array.c)

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

C supports multidimensional arrays, but we limit our discussion of multidimensional arrays to two-dimensional (2D) arrays, since 1D and 2D arrays are the most commonly used by C programmers.

## Statically Allocated

-[Statically Allocated 2D array](2d_array.c)

```
int   matrix[50][100];
short little[10][10];
```

Here, matrix is a 2D array of int values with 50 rows and 100 columns, and little is a 2D array of short values with 10 rows and 10 columns.

```
   matrix[2][3] = 8;
    matrix[49][99] = 13;
```
```
                    columns
          0     1     2     3     ...   99
       +-----+-----+-----+-----+-----+-----+
    0  |     |     |     |     | ... |     |
       +-----+-----+-----+-----+-----+-----+
    1  |     |     |     |     | ... |     |
       +-----+-----+-----+-----+-----+-----+
r   2  |     |     |     |  8  | ... |     |
o      +-----+-----+-----+-----+-----+-----+
w   3  |     |     |     |     | ... |     |
s      +-----+-----+-----+-----+-----+-----+
    4  |     |     |     |     | ... |     |
       +-----+-----+-----+-----+-----+-----+
    ⋮  |  ⋮  |  ⋮  |  ⋮  |  ⋮  |  ⋮  |  ⋮  |
       +-----+-----+-----+-----+-----+-----+
   49  |     |     |     |     | ... | 13  |
       +-----+-----+-----+-----+-----+-----+

matrix[2][3]   = 8;
matrix[49][99] = 13;
```
Programs often access the elements of a 2D array by iterating with nested loops.

```
int i, j;

for (i = 0; i < 50; i++) {  // for each row i
    for (j = 0; j < 100; j++) { // iterate over each column element in row i
        matrix[i][j] = 0;
    }
}
```

## Two-Dimensional Array Parameters

For multidimensional array parameters, you must indicate that the parameter is a multidimensional array, but you can leave the size of the first dimension unspecified (for good generic design).

-[2d array parameters](2d_array_parameter.c)

*The column dimension must be specified in the parameter definition of a 2D array so that the compiler can calculate the offset from the base address of the 2D array to the start of a particular row of elements. The offset calculation follows from the layout of 2D arrays in memory*

## Two-Dimensional Array Memory Layout

Statically allocated 2D arrays are arranged in memory in **row-major order**, meaning that all of row 0’s elements come first, followed by all of row 1’s elements, and so on.

```
int arr[3][4];

Address   Memory     Element
-------   --------   -------
1230:     |        |  [0][0]  --+
1234:     |        |  [0][1]    |
1238:     |        |  [0][2]    +-- Row 0
1242:     |        |  [0][3]  --+
          +--------+
1246:     |        |  [1][0]  --+
1250:     |        |  [1][1]    |
1254:     |        |  [1][2]    +-- Row 1
1258:     |        |  [1][3]  --+
          +--------+
1262:     |        |  [2][0]  --+
1266:     |        |  [2][1]    |
1270:     |        |  [2][2]    +-- Row 2
1274:     |        |  [2][3]  --+
          +--------+
 ...      |        |   ...
          +--------+

The layout of a two-dimensional array in row-major order.
```


## Dynamically Allocated 2D Arrays

-[Dynamically Allocated 2D Arrays](dynamically_allocated_2d_arrays.c)

Dynamically allocated 2D arrays can be allocated in two ways. For an NxM 2D array: (N = row , M = column)

Method 1: Memory-Efficient Allocation

In this method, a single call to malloc allocates the total number of bytes needed to store the NxM array of values. it is benefit of being more memory efficient

The compiler cannot distinguish this from a 1D array. It does not know what row or column it is. So it cannot be written as [i][j]. The programmer has to calculate the offset himself.

```
#define N 3
#define M 4

int *two_d_array;
two_d_array = malloc(sizeof(int) * N * M);  // 3*4 = 12
```

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Just definition
int Func(int *A, int nSize);

// Compare function for qsort
int cmp(const void *a, const void *b);

int main() {
  srand(time(NULL));
  int arr[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    // The `rand()` function generates too large number in some platforms :)
    arr[i] = rand() % 32768;
    if (arr[i] > 20000) {
      arr[i] = 0;
    }
  }

  printf("Generated array: ");
  for (int i = 0; i < SIZE; ++i) {
    if (i % 10 == 0) {
      putchar('\n');
    }
    printf("%-6d ", arr[i]);
  }
  putchar('\n');

  int pos = Func(arr, SIZE);

  printf("\nProcessed array: ");
  for (int i = 0; i < SIZE; ++i) {
    if (i % 10 == 0) {
      putchar('\n');
    }
    printf("%-6d ", arr[i]);
  }
  putchar('\n');
  if (pos == -1) {
    printf("No zero.\n");
  } else {
    printf("Index of first zero: %d", pos);
  }
  putchar('\n');
  return 0;
}

// Implementation
int Func(int arr[], int len) {
  qsort(arr, len, sizeof arr[0], cmp);

  int pos = -1;
  for (int i = 0; i < len; ++i) {
    if (arr[i] == 0) {
      return i;
    }
  }

  return -1;
}

int cmp(const void *a, const void *b) {
  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;

  if (arg1 < arg2) {
    return 1;
  }
  if (arg1 > arg2) {
    return -1;
  }
  return 0;
}

/*

## Environment

### System
OS: Arch Linux x86_64
Kernel: 6.1.13-lqx1-1-lqx
CPU: AMD Ryzen 5 5500U with Radeon Graphics (12) @ 2.100GHz

### Compiler
clang version 15.0.7
Target: x86_64-pc-linux-gnu
Thread model: posix

## Test Case

### Example 1

output:
```
Generated array:
0      2142   11671  0      9313   2866   5799   0      0      17701
0      0      8704   0      0      12598  0      0      19167  9290
0      1020   4737   17484  7247   1194   0      0      0      307
15344  0      2449   0      10707  11762  0      16507  11112  0
1440   0      0      10145  0      15403  0      9555   13974  9142
18845  4725   10163  0      0      17410  0      15860  10437  0
16167  0      12516  18617  0      0      0      17142  6962   8723
13571  8403   8124   8732   18548  0      0      8523   6707   5342
17666  0      10067  0      16368  0      12471  8377   15369  0
0      0      15922  11562  17386  3183   2018   14997  0      8980

Processed array:
19167  18845  18617  18548  17701  17666  17484  17410  17386  17142
16507  16368  16167  15922  15860  15403  15369  15344  14997  13974
13571  12598  12516  12471  11762  11671  11562  11112  10707  10437
10163  10145  10067  9555   9313   9290   9142   8980   8732   8723
8704   8523   8403   8377   8124   7247   6962   6707   5799   5342
4737   4725   3183   2866   2449   2142   2018   1440   1194   1020
307    0      0      0      0      0      0      0      0      0
0      0      0      0      0      0      0      0      0      0
0      0      0      0      0      0      0      0      0      0
0      0      0      0      0      0      0      0      0      0
Index of first zero: 61
```

*/

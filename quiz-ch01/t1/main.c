#include <math.h>
#include <stdio.h>

// Function 1 definition
void input2Array(double arr[], int len);

// Function 2 definition
void calculate(double arr[], int len, double *maxScore, double *minScore);

// Function 3 definition
void output(double arr[], int len, double maxScore, double minScore);

// mian
int main() {
  double arr[10] = {};
  input2Array(arr, 10);
  double maxScore, minScore;
  calculate(arr, 10, &maxScore, &minScore);
  output(arr, 10, maxScore, minScore);
  return 0;
}

// Function 1 implementation
void input2Array(double arr[], int len) {
  for (int i = 0; i < len; ++i) {
    double tmp = -114514.1919810;
    scanf("%lf", &tmp);
    while ((tmp < 0.) || (tmp > 100.)) {
      puts("\nInvalid input, out of [0.0, 100.0], please try again.");
      scanf("%lf", &tmp);
    }

    arr[i] = tmp;
  }
}

// Function 2 implementation
void calculate(double arr[], int len, double *maxScore, double *minScore) {
  *maxScore = -114514.1919810;
  *minScore = 114514.1919810;
  for (int i = 0; i < len; ++i) {
    if (arr[i] > *maxScore) {
      *maxScore = arr[i];
    }
    if (arr[i] < *minScore) {
      *minScore = arr[i];
    }
  }
}

// Function 3 implementation
void output(double arr[], int len, double maxScore, double minScore) {
  puts("\nMax score:");
  printf("%8s%8s\n", "No", "Score");

  for (int i = 0; i < len; ++i) {
    if (fabs(arr[i] - maxScore) < 1e-10) {
      printf("%8d%8.1lf\n", i + 1, arr[i]);
    }
  }

  puts("\nMin score:");
  printf("%8s%8s\n", "No", "Score");

  for (int i = 0; i < len; ++i) {
    if (fabs(arr[i] - minScore) < 1e-10) {
      printf("%8d%8.1lf\n", i + 1, arr[i]);
    }
  }
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

input:
```
-1 1 2 3 4 5 6 7 8 9 101 10
````

output:
```

Invalid input, out of [0.0, 100.0], please try again.

Invalid input, out of [0.0, 100.0], please try again.

Max score:
      No   Score
      10    10.0

Min score:
      No   Score
       1     1.0
```

### Example 2

input:
```
1 1 4 5 1 4 1 9 1 9
```

output:
```

Max score:
      No   Score
       8     9.0
      10     9.0

Min score:
      No   Score
       1     1.0
       2     1.0
       5     1.0
       7     1.0
       9     1.0
```

*/

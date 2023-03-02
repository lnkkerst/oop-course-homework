#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 114514

int main() {
  char s[MAX_SIZE];
  scanf("%s", s);

  char *ptr = &s[0];
  int last = 0;
  int fl = 0;
  while (*ptr) {
    if (isdigit(*ptr)) {
      last = last * 10 + (*ptr) - '0';
      fl = 1;
    } else {
      if (fl) {
        printf("%d\n", last);
      }
      last = 0;
      fl = 0;
    }
    ++ptr;
  }
  if (fl) {
    printf("%d\n", last);
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

input:
```
asd123rt456,fg789
```

output:
```
123
456
789
```

### Example 2

input:
```
wlysb114514sbwly1919810
```

output:
```
114514
1919810
```

*/

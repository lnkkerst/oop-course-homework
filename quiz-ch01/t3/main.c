#include <stdio.h>

int main() {
  const char *week[7];
  week[0] = "Monday";
  week[1] = "Tuesday";
  week[2] = "Wednesday";
  week[3] = "Thursday";
  week[4] = "Friday";
  week[5] = "Saturday";
  week[6] = "Sunday";
  int day;
  scanf("%d", &day);
  if (day < 1 || day > 7) {
    printf("Illegal\n");
    return 0;
  }
  printf("%s\n", *(week + (day - 1)));
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
0
```

output:
```
Illegal
```

### Example 2

input:
```
3
```

output:
```
Wednesday
```

*/

#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 114514

void solve(char *s, int *ans, int *cnt) {
  *cnt = 0;
  char *ptr = &s[0];
  int last = 0;
  int fl = 0;
  while (*ptr) {
    if (isdigit(*ptr)) {
      last = last * 10 + (*ptr) - '0';
      fl = 1;
    } else {
      if (fl) {
        ans[(*cnt)++] = last;
      }
      last = 0;
      fl = 0;
    }
    ++ptr;
  }
  if (fl) {
    ans[(*cnt)++] = last;
  }
}

int main() {
  char s[MAX_SIZE];
  scanf("%s", s);

  int ans[MAX_SIZE];
  int cnt;
  solve(s, ans, &cnt);

  printf("Total numbers: %d\n", cnt);
  for (int i = 0; i < cnt; ++i) {
    printf("%d\n", ans[i]);
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
Total numbers: 3
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
Total numbers: 2
114514
1919810
```

*/

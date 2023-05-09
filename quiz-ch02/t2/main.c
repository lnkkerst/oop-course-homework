#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Student {
  long num;      // 学号
  char name[20]; // 姓名
  // char sex;      // 性别
  float score; // 成绩
};

int cmp(const void *a, const void *b) {
  struct Student arg1 = *(const struct Student *)a;
  struct Student arg2 = *(const struct Student *)b;

  if (arg1.score < arg2.score) {
    return 1;
  }
  if (arg1.score > arg2.score) {
    return -1;
  }
  if (fabs(arg1.score - arg2.score) < 1e-5) {
    if (arg1.num < arg2.num) {
      return -1;
    }
    if (arg1.num > arg2.num) {
      return 1;
    }
  }
  return 0;
}

int main() {
  struct Student a[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    printf("Please input student %d id: ", i);
    scanf("%ld", &a[i].num);
    printf("\nPlease input student %d name: ", i);
    scanf("%s", a[i].name);
    printf("\nPlease input student %d math score: ", i);
    scanf("%f", &a[i].score);
  }

  qsort(a, SIZE, sizeof a[0], cmp);

  printf("\n%-8s%-22s%-8s", "id", "name", "math score");

  for (int i = 0; i < SIZE; ++i) {
    printf("\n%-8ld%-22s%-8f", a[i].num, a[i].name, a[i].score);
  }
}

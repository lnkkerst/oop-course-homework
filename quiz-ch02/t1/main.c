#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  long num;      // 学号
  char name[20]; // 姓名
  char sex;      // 性别
  float score;   // 成绩
};

struct SLink {
  struct Student s;
  struct SLink *next;
} *head = NULL;

void createLink() {
  head = (struct SLink *)malloc(sizeof(struct SLink));
  head->next = NULL;
}

void insertData(struct Student s) {
  struct SLink *p, *q, *np;

  np = (struct SLink *)malloc(sizeof(struct SLink));
  np->s = s;
  np->next = NULL;

  p = head;
  q = p->next;

  while (q != NULL && s.num > q->s.num) {
    p = q;
    q = q->next;
  }

  np->next = q;
  p->next = np;
}

void deleteData(long num) {
  struct SLink *p, *q;

  p = head;
  q = p->next;

  while (q != NULL && q->s.num != num) {
    p = q;
    q = q->next;
  }

  if (q != NULL) {
    p->next = q->next;
    free(q);
  }
}

void printLink() {
  struct SLink *p;

  p = head->next;

  while (p != NULL) {
    printf("%ld %s %c %.1f\n", p->s.num, p->s.name, p->s.sex, p->s.score);
    p = p->next;
  }
}

int main() {
  printf("正在建立链表...\n");
  createLink();

  struct Student s1 = {10001, "张三", 'M', 11.4};
  struct Student s2 = {10003, "李四", 'M', 51.4};
  struct Student s3 = {10002, "王五", 'F', 100.};

  insertData(s1);
  insertData(s2);
  insertData(s3);

  printf("链表初始数据：\n");
  printLink();

  printf("删除学号为 10003 的数据\n");
  deleteData(10003);

  printf("删除后的链表：\n");
  printLink();

  return 0;
}

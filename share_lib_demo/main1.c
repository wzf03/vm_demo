#include "add.h"
#include "stdio.h"

int main() {
  int a = 1;
  int b = 2;
  int c = add(a, b);
  printf("%d + %d = %d\n", a, b, c);

  getchar();
  return 0;
}
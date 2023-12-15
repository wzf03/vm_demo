#include "add.h"
#include "stdio.h"

int main() {
  int sum = 0;
  for (int i = 1; i <= 10; i++) {
    sum = add(sum, i);
  }
  printf("sum = %d\n", sum);

  getchar();
  return 0;
}
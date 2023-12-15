#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

int main() {
  int fd = open("data.bin", O_CREAT | O_RDWR, 0644);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  int n = 1000000;
  if (ftruncate(fd, n * sizeof(double)) < 0) {
    perror("ftruncate");
    close(fd);
    return 1;
  }

  double *data_ptr = (double *)mmap(NULL, n * sizeof(double),
                                    PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
  if (data_ptr == MAP_FAILED) {
    perror("mmap");
    close(fd);
    return 1;
  }

  srand(time(0));

  for (int i = 0; i < n; i++) {
    data_ptr[i] = (double)rand() / RAND_MAX;
  }

  munmap(data_ptr, n * sizeof(double));
  close(fd);
  return 0;
}

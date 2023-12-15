#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd = open("data.bin", O_RDONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  struct stat st;
  if (fstat(fd, &st) < 0) {
    perror("fstat");
    close(fd);
    return 1;
  }

  int n = st.st_size / sizeof(double);
  double *data_ptr =
      (double *)mmap(NULL, n * sizeof(double), PROT_READ, MAP_SHARED, fd, 0);
  if (data_ptr == MAP_FAILED) {
    perror("mmap");
    close(fd);
    return 1;
  }

  int counts[10], out_of_range = 0;
  memset(counts, 0, sizeof(counts));

  for (int i = 0; i < n; i++) {
    // count the number of random numbers in each range
    if (data_ptr[i] < 0 || data_ptr[i] > 1) {
      out_of_range++;
    } else {
      counts[(int)(data_ptr[i] * 10)]++;
    }
  }

  printf("Out of range: %d\n", out_of_range);
  for (int i = 0; i < 10; i++) {
    printf("%.1f - %.1f: %d\n", i / 10.0, (i + 1) / 10.0, counts[i]);
  }

  munmap(data_ptr, n * sizeof(double));
  close(fd);
  return 0;
}
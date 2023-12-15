#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t a_number = 0;

void sigusr1_handler(int signo) { a_number = 1; }

int main() {
  signal(SIGUSR1, sigusr1_handler);
  int parent = 0;

  if (fork() != 0)
    parent = 1;

  pid_t pid = getpid();

  printf("%s pid: %d\n", parent ? "parent" : "child", pid);

  while (1) {
    pause();
  }

  return 0;
}
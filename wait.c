#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  int pid = fork();
  if (pid>0) {
    printf("parent: child=%d\n", pid);
    int ret;
    pid = wait(&ret);
    printf("child %d : %d is done\n", pid, ret);
  } else if (pid == 0) {
    sleep(20);
    printf("child exiting");
    exit(2);
  } else {
    printf("fork error %d\n", pid);
  }
}

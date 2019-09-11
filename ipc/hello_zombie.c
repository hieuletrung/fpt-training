// file - hello_zombie.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 150

int main()
{
  int pid = fork();
  char buf[BUF_SIZE];
  int print_count;

  switch (pid)
  {
    case -1:
      perror("fork failed");
      exit(1);
    case 0:
      print_count = 2;
      sprintf(buf,"child process: pid = %d", pid);
      break;
    default:
      print_count = 10;
      sprintf(buf,"parent process: pid = %d", pid);
      break;
  }
  for(;print_count > 0; print_count--) {
      puts(buf);
      sleep(1);
  }
  exit(0);
}
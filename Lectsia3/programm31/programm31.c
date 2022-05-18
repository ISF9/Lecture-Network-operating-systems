#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;
int main() 
{
    int sz;
  char * c = (char * ) calloc(100, sizeof(char));
  int fd = open("foo.txt", O_RDONLY | O_CREAT);
  printf("fd = %d\n", fd);
  if (fd == -1) 
  {
    printf("Error Number % d\n", errno);
    perror("open file error:");
  }
  sz = read(fd, c, 10);
  printf("called read(% d, c, 10). returned that"
    " %d bytes were read.\n", fd, sz);
  c[sz] = '\0';
  if (close(fd) < 0) 
  {
    perror("close file error:");
    exit(1);
  }
   printf("closed the fd.\n");
  return 0;
}

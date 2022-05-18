#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define NAMEDPIPE_NAME "mypipe15" 
#define BUFSIZE 50

int main(int argc, char ** argv) 
{
  int fd; 
  int len;
  char buf[BUFSIZE];
  if (mkfifo(NAMEDPIPE_NAME, 07777)) 
{ 
    perror("mkfifo");
    return 1;
  }
  printf("%s is created\n", NAMEDPIPE_NAME);
  if ((fd = open(NAMEDPIPE_NAME, O_RDONLY)) <= 0) 
{
    perror("open error:");
    return 1;
  }
  printf("%s is opened\n", NAMEDPIPE_NAME);
  do 
{
    memset(buf, '\0', BUFSIZE);
    if ((len = read(fd, buf, BUFSIZE - 1)) <= 0) 
{
      perror("read error");
      close(fd);
      remove(NAMEDPIPE_NAME);
      return 0;
    }
    printf("Incomming message (%d): %s\n", len, buf);
  } while (1);
}

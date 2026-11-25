#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main() 
{ 
int fd1,fd2; 
char buff[]="Hello World";
fd1 = open("ex1.txt", O_RDWR|O_CREAT|O_EXCL, 0777);
if (fd1==-1)
perror("Reason:"); else
{
perror("Reason"); 
write(fd1, buff,
sizeof(buff));
}
} 

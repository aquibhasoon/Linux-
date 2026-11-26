#include <unistd.h>
#include <stdio.h>



int main()
{
int ret=fork();
if (ret==0)
{
printf("This message is from child %d \n",getpid());
printf("PPID before sleep is: %d\n", getppid());
sleep(5);
printf("PID after sleep: %d\n",getpid());
printf("PPID after sleep is :%d\n",getppid());
}
else
{
printf("This messsage is from Parent %d \n",getpid());
sleep(10);
}

return 0;
}

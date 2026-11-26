#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main()
{
pid_t ret=fork();
if (ret==-1)
{
perror("fork");
return 1;
}

if (ret==0)
{
printf("This message is from child %ld \n",(long)getpid());
printf("PPID before sleep is: %ld\n", (long)getppid());
sleep(5);
printf("PID after sleep: %ld\n",(long)getpid());
printf("PPID after sleep is :%ld\n",(long)getppid());
return 7;
}

printf("This messsage is from Parent %ld \n",(long)getpid());
int status;
pid_t waited_pid=wait(&status);

if (waited_pid==-1)
{
perror("wait");
return 1;
}
printf("wait() returned :%ld\n",(long)waited_pid);
printf("Raw status :%d\n",status);

if (WIFEXITED(status))
{
printf("child exit code :%d\n",(WEXITSTATUS(status)));
}


return 0;
}

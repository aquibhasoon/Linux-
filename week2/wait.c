#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int sqrtp(int x, int y, int z)
{
    int result = ((y * y) + (4 * x * z)) / (2 * x);
    return result;
}

int sqrtn(int x, int y, int z)
{
    int result = ((y * y) - (4 * x * z)) / (2 * x);
    return result;
}

int main(void)
{

    int a, b, c;
    printf("Enter the value of a,b,c in order: \n");
    scanf("%d %d %d", &a, &b, &c);

    pid_t ret = fork();
    if (ret == -1)
    {
        perror("wait child1");
        return 1;
    }

    if (ret == 0)
    {
        return sqrtp(a, b, c);
    }

    int status;
    pid_t waited_pid = wait(&status);

    if (waited_pid == -1)
    {
        perror("wait child 1");
        return 1;
    }

    if (WIFEXITED(status))
    {
        printf("child1 result is :%d\n", (WEXITSTATUS(status)));
    }

    pid_t ret1 = fork();
    if (ret1 == -1)
    {
        perror("child2");
        return 1;
    }

    if (ret1 == 0)
    {
        return sqrtn(a, b, c);
    }

    waited_pid = wait(&status);

    if (waited_pid == -1)
    {
        perror("wait child 2");
        return 1;
    }

    if (WIFEXITED(status))
    {
        printf("child2 result is :%d\n", (WEXITSTATUS(status)));
    }

    return 0;
}


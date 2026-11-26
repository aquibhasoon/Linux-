#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int sqrtn(int x, int y, int z)
{
    return ((y * y) - (4 * x * z)) / (2 * x);
}

int main(void)
{
    int a, b, c;

    printf("Enter the values of a, b, c in order:\n");
    if (scanf("%d %d %d", &a, &b, &c) != 3 || a == 0) {
        printf("Enter three integers with a nonzero a.\n");
        return 1;
    }

    pid_t ret = fork();
    if (ret == -1) {
        perror("fork child 1");
        return 1;
    }

    if (ret == 0) {
        execl("/bin/date", "date", (char *)NULL);
        perror("execl");
        _exit(1);
    }

    int status;
    pid_t waited_pid = wait(&status);

    if (waited_pid == -1) {
        perror("wait child 1");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("Child 1 (date) exit code: %d\n", WEXITSTATUS(status));
    }

    pid_t ret1 = fork();
    if (ret1 == -1) {
        perror("fork child 2");
        return 1;
    }

    if (ret1 == 0) {
        _exit(sqrtn(a, b, c));
    }

    waited_pid = wait(&status);

    if (waited_pid == -1) {
        perror("wait child 2");
        return 1;
    }

    if (WIFEXITED(status)) {
        printf("Child 2 result: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
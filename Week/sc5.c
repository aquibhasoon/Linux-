#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t result = fork();

    if (result < 0) {
        perror("fork");
        return 1;
    }

    if (result == 0) {
        /* Child process */
        printf("Child: Hello from the child process.\n");
        printf("Child PID: %ld\n", (long)getpid());
        printf("Parent PID: %ld\n", (long)getppid());
    } else {
        /* Parent process */
        printf("Parent: Hello from the parent process.\n");
        printf("Parent PID: %ld\n", (long)getpid());
        printf("Child PID: %ld\n", (long)result);
    }

    return 0;
}

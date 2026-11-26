#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    char command[50];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(command, sizeof command, stdin) == NULL) {
            break;
        }

        if (strcmp(command, "exit\n") == 0) {
            break;
        }

        if (strcmp(command, "ls\n") != 0 &&
            strcmp(command, "pwd\n") != 0 &&
            strcmp(command, "date\n") != 0) {
            printf("Enter ls, pwd, date, or exit.\n");
            continue;
        }

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            if (strcmp(command, "ls\n") == 0) {
                execl("/bin/ls", "ls", (char *)NULL);
            } else if (strcmp(command, "pwd\n") == 0) {
                execl("/bin/pwd", "pwd", (char *)NULL);
            } else {
                execl("/bin/date", "date", (char *)NULL);
            }

            perror("execl");
            _exit(1);
        }

        if (wait(NULL) == -1) {
            perror("wait");
        }
    }

    return 0;
}
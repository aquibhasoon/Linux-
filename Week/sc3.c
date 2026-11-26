#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("User ID: %d\n", getuid());
    printf("Group ID : %d\n",getgid());
    return 0;
}

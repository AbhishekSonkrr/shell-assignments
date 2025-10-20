#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        printf("Child: pid=%d parent=%d\n", getpid(), getppid());
        _exit(0);
    } else {
        printf("Parent: child pid=%d\n", pid);
        wait(NULL);
    }
    return 0;
}

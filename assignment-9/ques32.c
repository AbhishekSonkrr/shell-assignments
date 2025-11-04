#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // Child process: run "ls -l"
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        return 1;
    } else {
        // Parent process: wait for child
        wait(NULL);
        printf("Command executed.\n");
    }
    return 0;
}
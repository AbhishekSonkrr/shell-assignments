#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s cmd1 cmd2\n", argv[0]);
        fprintf(stderr, "Example: %s ls grep .c\n", argv[0]);
        return 1;
    }
    int fd[2];
    if (pipe(fd) != 0) { perror("pipe"); return 1; }
    pid_t p = fork();
    if (p < 0) { perror("fork"); return 1; }
    if (p == 0) {
        // child: run cmd1, write to pipe
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        execlp(argv[1], argv[1], (char*)NULL);
        perror("execlp"); exit(1);
    } else {
        // parent: run cmd2, read from pipe
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        execlp(argv[2], argv[2], (char*)NULL);
        perror("execlp"); exit(1);
    }
    return 0;
}

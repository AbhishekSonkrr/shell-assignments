#include <stdio.h>
#include <unistd.h>   // for fork(), getpid()
#include <sys/types.h> 

int main() {
    printf("Program started. PID = %d\n", getpid());

    int pid = fork();   // child create

    if (pid < 0) 
    {
        // fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child process:\n");
        printf("  Child PID = %d\n", getpid());
        printf("  Parent of Child = %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent process:\n");
        printf("  Parent PID = %d\n", getpid());
        printf("  Child PID  = %d\n", pid);
    }

    printf("Common code: Executed by both parent and child\n");

    return 0;
}
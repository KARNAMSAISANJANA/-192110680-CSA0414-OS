#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid, parent_pid;
    
 
    pid = fork();
    
 
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    
    if (pid > 0) {
        printf("parent process: pid=%d, parent_pid=%d\n", getpid(), getppid());
    }
    
    if (pid == 0) {
        printf("child process: pid=%d, parent_pid=%d\n", getpid(), getppid());
    }
    
    return 0;
}


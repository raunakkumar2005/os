#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("This is the child process\n");
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        printf("This is the parent process\n");
        wait(NULL);
        printf("Child process has finished executing\n");
    }
    return 0;
}

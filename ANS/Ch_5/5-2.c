#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // redirect standard output to a file
    close(STDOUT_FILENO);
    open("./2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        printf("fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        for (int i = 0; i < 10000; i++)
            printf("I am the child : %d\n", (int)getpid());
    }
    else {
        for (int i = 0; i < 10000; i++)
            printf("I am main : %d\n", (int)getpid());
    }
    return 0;
}

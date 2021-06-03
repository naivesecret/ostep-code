#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 1;
    printf("x is %d (pid:%d)\n", x, (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // child (new process)
        x = 10;
        printf("x is %d, I am child (pid:%d)\n", x, (int)getpid());
    }
    else {
        // parent goes down this path (original process)
        x = 5;
        printf("x is %d, I am parent of %d (pid:%d)\n", x, rc, (int)getpid());
    }
    return 0;
}

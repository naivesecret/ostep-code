#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int rc = fork();
    int wc = wait(NULL);
    if (rc < 0) {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0) {
        printf("child");
    }
    else {
        printf("parent");
    }
    printf("pid: %d  wc: %d  rc: %d\n", (int)getpid(), wc, rc);
    return 0;
}

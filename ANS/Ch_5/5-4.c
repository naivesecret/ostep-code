#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const int FLAGS = 6;
    char* s = "/bin/ls";
    char* ss = "ls";
    char* s2 = "/";
    char* sv[] = {ss, s2, NULL};
    for (int i = 0; i < FLAGS; ++i) {
        int rc = fork();
        if (rc < 0) {
            fprintf(stderr, "fork failed");
            exit(1);
        }
        else if (rc == 0) {
            switch (i) {
                case 0:
                    execl(s, ss, s2, NULL);
                    break;
                case 1:
                    execle(s, ss, s2, NULL);
                    break;
                case 2:
                    execlp(s, s, s2, NULL);
                    break;
                case 3:
                    execv(s, sv);
                    break;
                case 4:
                    execvp(ss, sv);
                    break;
                case 5:
                    execvpe(ss, sv);
                    break;
                default:
                    break;
            }
        }
        else {
            wait(NULL);
        }
    }
    return 0;
}
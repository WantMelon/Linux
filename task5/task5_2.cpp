#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

using namespace std;

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) perror("Fork");
    if (pid == 0) {
        if (execl("/bin/xz", "xz", "-z", "output.txt", NULL) == -1)
            perror("xz");
    }
    return 0;
}

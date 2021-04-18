#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

using namespace std;

int main() {
//iconv -f CP1251 -t UTF-8 file.txt -o output.txt

    pid_t pid;
    pid = fork();

    if (pid < 0) perror("Fork");
    if (pid == 0) {
        if (execl("/usr/bin/iconv", "iconv", "-f", "CP1251", "-t", "UTF-8", "input.txt", "-o", "output.txt", NULL) == -1)
            perror("iconv");
    }
    return 0;
}

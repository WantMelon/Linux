#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Error argc should be 2\n";
        return 1;
    }
    if (argv[1][0] != '-') {
        cerr << "Program should be in format ./multieyes -n" << endl;
        return 1;
    }

    int num = atoi(argv[1]);
    num *= -1;

    int pid;

    while (num--) {
        pid = fork();
        if (pid == -1) {
            perror("Fork");
        }
        if (pid == 0) {
            if(execl("/usr/bin/xeyes", "xeyes", 0) == -1) {
                perror("Execl");
                return 1;
            }
        }

    }

    //cout << num << endl;
    return 0;
}

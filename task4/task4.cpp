#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    pid_t pid;
    int status;
    //char* new_env[] = {"SHELL", NULL};
    pid = fork();
    if (pid < 0) perror("Fork");
    if (pid == 0) {
        status = execl("/bin/gedit", "gedit", "file.txt", (char *)NULL);
        if (status == -1) perror("Exec");
    } else {
        cout << "Child pid: " << pid << endl;
        sleep(10);
    }

    return 0;
}

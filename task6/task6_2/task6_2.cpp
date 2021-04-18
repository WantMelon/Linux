#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include <sys/stat.h>
#include <fcntl.h>


using namespace std;

void write_info(int s) {
    int fd = open("log1.txt", O_CREAT | O_WRONLY, 0666);
    if (fd < 0) {
        perror("open");
    }
    char message[] = "sigill1\n";
    if (write(fd, message, strlen(message)) < 0) {
        perror("write");
    }
}
//g++ task6.cpp -o task6 -pthread
int main() {

    sigset_t set;
    if (sigfillset(&set) == -1) {
        perror("sigfillset");
        return -1;
    }
    pthread_sigmask(SIG_SETMASK, &set, NULL);

    struct sigaction act;
    act.sa_handler = write_info;
    sigaction(SIGILL, &act, NULL);

    sigemptyset(&set);
    pthread_sigmask(SIG_SETMASK, &set, NULL);


    /*if (kill(0, SIGILL) == -1)
    {
        perror("kill");
    }*/

    asm("ud2");

    while (true) {
        pause();
    }

    return 0;
}

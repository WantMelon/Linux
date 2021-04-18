#include <iostream>
#include <signal.h>
#include <unistd.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//g++ task6.cpp -o task6 -pthread
int main() {
    sigset_t set;
    if (sigfillset(&set) == -1) {
        perror("sigfillset");
        return -1;
    }
    pthread_sigmask(SIG_SETMASK, &set, NULL);

    struct sigaction act;
    act.sa_handler = SIG_IGN;
    sigaction(SIGTERM, &act, NULL);

    sigemptyset(&set);
    pthread_sigmask(SIG_SETMASK, &set, NULL);

    while (true) {
        pause();
    }

    return 0;
}

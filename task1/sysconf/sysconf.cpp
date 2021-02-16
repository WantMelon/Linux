#include <iostream>
#include <unistd.h>

using namespace std;

long sysconf(int name);

int main()
{
    cout << "OPEN_MAX: " << sysconf(_SC_OPEN_MAX) << endl;
    cout << "ARG_MAX: " << sysconf(_SC_ARG_MAX) << endl;
    cout << "POSIX_VERSION: " << sysconf(_SC_VERSION) << endl;

    return 0;
}

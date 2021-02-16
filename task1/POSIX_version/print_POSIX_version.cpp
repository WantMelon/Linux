#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "POSIX version in YYYY-MM format: " << _POSIX_VERSION << endl;
    cout << "SUS version: " << _XOPEN_VERSION << endl;

    return 0;
}

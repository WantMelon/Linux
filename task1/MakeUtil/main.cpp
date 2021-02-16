#include "header.h"

using namespace std;

int main()
{
    int degree;
    double num;

    cout << "Input number and degree to power: \n";
    cin >> num >> degree;

    cout << num << "^" << degree << " = " << fun(num, degree) << endl;
    return 0;
}

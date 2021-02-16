#include "header.h"

using namespace std;

double fun(double num, int degree)
{
    double res = 1.0;
    for (int i = 0; i < degree; i++)
    {
        res *= num;
    }
    return res;
}

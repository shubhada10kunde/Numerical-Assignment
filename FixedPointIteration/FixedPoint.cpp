#include <bits/stdc++.h>
#include "FixedPoint.hpp"
using namespace std;

FixedPoint::FixedPoint()
{
    cout << "Fixed Point Iteration...." << endl;
}
double FixedPoint::f(double x)
{
    return ((x * x) + 2) / 4;
}

double FixedPoint::FixedPointIteration()
{
    int iteration(0);
    do
    {
        previous = x0;
        x0 = f(x0);
        iteration++;
        cout << "Iteration " << iteration << ":: x = " << x0 << "\t previous :: " << previous << "\t fabs(x0 - previous) :: " << fabs(x0 - previous) << endl;
    } while (fabs(x0 - previous) > ToL);
    this->root = x0;
    cout << "The root of equation is:: " << root << endl;
}
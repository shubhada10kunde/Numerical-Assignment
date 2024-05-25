#include <bits/stdc++.h>
#include "NewtonRaphson.hpp"
using namespace std;

RootFinding::RootFinding()
{
    cout << "Root finding using newton raphson method....." << endl;
}

double RootFinding::f(double x)
{
    return ((x * x) - (4 * x) + 2);
}
double RootFinding::f_dash(double x)
{
    return ((2 * x) - 4);
}

double RootFinding::NewtonRaphson()
{
    int iteration(0);
    do
    {
        previous = x0;
        x0 = x0 - (f(x0) / f_dash(x0));
        iteration++;
        cout << "Iteration " << iteration << ":: x = " << x0 << "\t previous :: " << previous << "\t fabs(x0 - previous) :: " << fabs(x0 - previous) << endl;
    } while (fabs(x0 - previous) > ToL);
    this->root = x0;
    cout << "The root of equation is:: " << root << endl;
    // return root;
}
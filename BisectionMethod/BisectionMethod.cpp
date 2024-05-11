#include <bits/stdc++.h>
#include "BisectionMethod.hpp"
using namespace std;

double TOL = 0.00001;

RootFinding::RootFinding()
{
    cout << "Root finding using bisection method..." << endl;
}

double f(double x)
{
    return x * x - 4; // Change this function according to your requirement
}

double RootFinding::Bisection()
{

    double a = 0, b = 0;
    double M = (a + b) / 2;

    while (fabs(f(M)) > TOL)
    {
        if (f(M) * f(a) < 0)
        {
            b = M;
        }
        else
        {
            a = M;
        }

        M = (a + b) / 2;
    }
    return M;
    root = M;
    cout << "Root" << root << endl;
}
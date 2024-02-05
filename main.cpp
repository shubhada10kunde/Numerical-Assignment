#include <iostream>
#include "MyComplex.hpp"
using namespace std;

int main()
{
    MyComplex c1, c2, c3, c4;
    c1.print();

    c1.real = 10;
    c1.img = 5;
    cout << endl;
    c1.print();
    cout << endl;

    c2.real = 5;
    c2.img = 3;
    cout << endl;
    c2.print();
    cout << endl;

    c3.print();
    cout << endl;

    cout << "addition :" << endl;
    c3.addition(c1, c2);
    c3.print();
    cout << endl;

    cout << endl;
    cout << "subtraction :" << endl;
    c3.subtraction(c1, c2);
    c3.print();
    cout << endl;

    cout << endl;
    cout << "multiplication :" << endl;
    c3.multiplication(c1, c2);
    c3.print();
    cout << endl;

    cout << endl;
    cout << "division :" << endl;
    c3.division(c1, c2);
    // c3.print();
    cout << endl;

    cout << endl;
    cout << "magnitude :" << endl;
    c3.norm(c1, c2);
    // c3.print();
    cout << endl;

    cout << "conjugate :" << endl;
    c4.complexConjugate(c1, c2);
    // c4.print();
    cout << endl;
    return 0;
}
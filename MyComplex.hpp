class MyComplex
{
public:
    double real;
    double img;

    MyComplex(); // default constructor

    void print(); // function to print complex no

    void addition(MyComplex, MyComplex);
    void subtraction(MyComplex, MyComplex);
    void multiplication(MyComplex, MyComplex);
    void division(MyComplex, MyComplex);
    void norm(MyComplex, MyComplex);
    void complexConjugate(MyComplex, MyComplex);
};
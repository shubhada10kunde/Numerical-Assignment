#include <iostream>
#include <vector>
// #include <fstream>
#include <string>
// #include <bits/stdc++.h>
// using namespace std;

class Matrix
{
private:
    std::string MatrixFile;
    int Rows, Cols;
    std::vector<std::vector<double>> Mat;
    double TOL = 0.01;

public:
    Matrix();

    void ReadMatrixFromFile(std::string);
    void PrintMatrix();
    bool isDiagonallyDominant();
    bool MakeDiagonallyDominant();
    int getDiagonallyDominantRowAt(int);
    int SwapRows(int, int);

    // bool isDiagonallyDominant();
    void GaussSeidel();
};

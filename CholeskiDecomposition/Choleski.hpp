#include <vector>

class Matrix
{
public:
    int Rows, Cols;
    std::vector<std::vector<double>> Mat;

    Matrix();
    Matrix(int, int);

    void ReadMatrixFromFile(std::string);
    void PrintMatrix();
    bool isSymmetric();
    void CholeskyDecomposition();

    double getDiagonalElement(Matrix, int);
    double getLowerTriangularMatrix(Matrix, int, int);

    // void getLowerTriangularMatrix();
};
#include <bits/stdc++.h>
#include "GaussJacobi.hpp"
using namespace std;

double TOL = 0.00001;
Matrix::Matrix() // default constructor
{
    cout << "Gauss Jacobi...!" << endl;
};

// declaring globally
string MatrixFile = "3x4_matrix.txt";
int Rows, Cols;
vector<vector<double>> Mat;

// Function to read the matrix from file
void Matrix::ReadMatrixFromFile()
{
    ifstream Fin;
    Fin.open(MatrixFile);
    if (!Fin)
    {
        cerr << "Error:Unable to open matrix file!" << endl;
        exit(1);
    }

    Fin >> Rows >> Cols;
    cout << "\n No of rows::" << Rows << "\tNo of cols::" << Cols << endl;

    Mat = vector<vector<double>>(Rows, vector<double>(Cols));
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Fin >> Mat[i][j];
        }
    }
    Fin.close();
}

// Function to print a matrix
void Matrix::PrintMatrix()
{
    for (int i = 0; i < Mat.size(); i++)
    {
        for (int j = 0; j < Mat[i].size(); j++)
        {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::GaussJacobi()
{
    if (!isDiagonallyDominant())
    {
        // MakeDiagonallyDominant();
        // if (!MakeDiagonallyDominant())
        // {
        //     cerr << "Unable to make the matrix diagonally dominant" << endl;
        //     return;
        // }
    }

    int flag = 0;
    int whileCnt = 0;
    double prev[Cols - 1];
    double Answer[Cols - 1];
    for (int i = 0; i < Cols - 1; i++)
    {
        Answer[i] = 0;
        prev[i] = 0;
    }

    while (1)
    {
        ++whileCnt;
        cout << " Iteration :: " << whileCnt << endl;
        for (int r = 0; r < Rows; r++)
        {
            double LHS = 0;
            for (int c = 0; c < Cols - 1; c++)
            {
                if (r != c)
                {
                    LHS += Mat[r][c] * prev[c];
                }
            }
            double RHS = (-LHS + Mat[r][Cols - 1]) / Mat[r][r];
            Answer[r] = RHS;
        }
        for (int i = 0; i < Cols - 1; i++)
        {
            cout << " i :: " << i << "\t Prev ::" << fabs(prev[i]) << "\t Answer :: " << fabs(Answer[i]) << " \t Prev - Answer :: " << fabs(fabs(prev[i]) - fabs(Answer[i])) << endl;
            if (fabs(fabs(prev[i]) - fabs(Answer[i])) < TOL)
            {
                flag = 1; // Update flag if condition is met
                cout << "\n Breaking...\n";
                break;
            }
        }

        if (flag == 1)
            break;

        // Update prev
        // double prev[Cols - 1];
        for (int i = 0; i < Cols - 1; i++)
            prev[i] = Answer[i];
    }
}
// void Matrix::PrintMatrix()
// {
//     for (int i = 0; i < mat.size(); i++) // Loop for each row of the matrix
//     {
//         for (int j = 0; j < mat[i].size(); j++) // Loop for each element of the current row
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// Reading Left Matrix from file

// std::ifstream LeftFile(LeftMatrixFile);
// if (!LeftFile)
// {
//     std::cerr << "Error: Unable to open Left matrix file!" << std::endl;
//     return 1;
// }
// std::vector<std::vector<double>> LeftMat(Rows, std::vector<double>(Cols));
// for (int i = 0; i < Rows; ++i)
// {
//     for (int j = 0; j < Cols; ++j)
//     {
//         Fin >> LeftMat[i][j];
//     }
// }
// LeftFile.close();

// // Reading Right matrix from the file
// std::ifstream RightFile(RightMatrixFile);
// if (!RightFile)
// {
//     std::cerr << "Error: Unable to open Right matrix file!" << std::endl;
//     return 1;
// }

// std::vector<std::vector<double>> RightMat(Rows, std::vector<double>(Cols));
// for (int i = 0; i < Rows; ++i)
// {
//     for (int j = 0; j < Cols; ++j)
//     {
//         Fin >> RightMat[i][j];
//     }
// }
// RightFile.close();

// // Print left matrix
// std::cout << "Left Matrix::" << std::endl;
// for (int i = 0; i < Rows; i++)
// {
//     for (int j = 0; j < Cols; j++)
//     {
//         std::cout << LeftMat[i][j] << " ";
//     }
//     std::cout << std::endl;
// }
// std::cout << std::endl;

// // Print Right matrix
// std::cout << "Right Matrix::" << std::endl;
// for (int i = 0; i < Rows; i++)
// {
//     for (int j = 0; j < Cols; j++)
//     {
//         std::cout << RightMat[i][j] << " ";
//     }
//     std::cout << std::endl;
// }
// std::cout << std::endl;

// std::vector<std::vector<double>> ReadMatrixFromFile(const std::string &MatrixFile, int &Rows, int &Cols)

bool Matrix::isDiagonallyDominant()
{
    bool isDominant = true;

    for (int r = 0; r < Rows; r++)
    {
        double sum = 0;
        for (int c = 0; c < Cols - 1; c++)
        {
            if (r != c)
            {
                sum += fabs(Mat[r][c]);
            }
        }
        if (fabs(Mat[r][r]) < sum)
        {
            isDominant = false;
            break;
        }
    }

    if (isDominant)
    {
        cout << "The Matrix is Diagonally dominant" << endl;
    }
    else
    {
        cout << "The matrix is not diagonally dominant" << endl;
    }
    return isDominant;
}

// Function to make the matrix diagonally dominant
bool Matrix::MakeDiagonallyDominant()
{
    for (int r = 0; r < Rows; r++)
    {
        double sum = 0;
        for (int c = 0; c < Cols; c++)
        {
            if (r != c)
                sum += fabs(Mat[r][c]);
        }
        if (sum > fabs(Mat[r][r]))
        {
            int index = getDiagonallyDominantRowAt(r);

            if (index = -1)
            {
                SwapRows(r, index);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

// Function to find the next row that can make the matrix diagonally dominant
int Matrix::getDiagonallyDominantRowAt(int r)
{
    for (int i = r + 1; i < Rows; i++)
    {
        double sum = 0.0;
        for (int c = 0; c < Cols; c++)
        {
            // if (r != c)
            sum += fabs(Mat[i][c]);
        }
        if (fabs(Mat[i][i] >= sum))
        {
            return i;
        }
    }
    cout << "Not possible to make diagonally dominant" << endl;
    return -1;
}

// Function to swap two rows of the matrix
int Matrix::SwapRows(int r1, int r2)
{
    for (int i = 0; i < Cols; i++)
    {
        double temp;
        temp = Mat[r1][i];
        Mat[r1][i] = Mat[r2][i];
        Mat[r2][i] = temp;
    }
}
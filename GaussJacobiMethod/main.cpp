// #include <bits/stdc++.h>
#include <iostream>
// #include <vector>
// #include <fstream>
// #include <sstream>
#include "GaussJacobi.hpp"
using namespace std;

int main()
{
    Matrix matrix;

    matrix.ReadMatrixFromFile();
    matrix.PrintMatrix();
    // matrix.isDiagonallyDominant();
    // matrix.MakeDiagonallyDominant();
    matrix.GaussJacobi();
    // matrix.getDiagonallyDominantRowAt();
    // matrix.SwapRows();

    // std::string MatrixFile = "3x4_matrix.txt";

    // auto leftMat = ReadMatrixFromFile(LeftMatrixFile, leftRows, leftCols);
    // auto rightMat = ReadMatrixFromFile(RightMatrixFile, rightRows, rightCols);

    // Print matrices
    // std::cout << "Left Matrix:" << std::endl;
    // matrix.PrintMatrix(leftMat);
    // std::cout << "\nRight Matrix:" << std::endl;
    // matrix.PrintMatrix(rightMat);

    // std::ifstream Fin;
    // Fin.open(LeftMatrixFile);

    // int Rows, Cols;
    // Fin >> Rows >> Cols;
    // std::cout << "\n No of rows::" << Rows << "\tNo of cols::" << Cols << std::endl;

    // // Reading Left Matrix from file
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

    // matrix.GaussJacobi();

    return 0;
}
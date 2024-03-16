// #include <iostream>
// #include <fstream>
#include <bits/stdc++.h>
using namespace std;

// Function to print a matrix
void PrintMatrix(const vector<vector<double>> &mat)
{
    for (int i = 0; i < mat.size(); i++) // Loop for each row of the matrix
    {
        for (int j = 0; j < mat[i].size(); j++) // Loop for each element of the current row
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string FileName_L = "Gaussian_Left.txt";
    string FileName_R = "Gaussian_Right.txt";

    ifstream Fin;
    Fin.open(FileName_L);

    int rows_Left, cols_Left;
    Fin >> rows_Left >> cols_Left;
    cout << "\n rows::" << rows_Left << "\tcols::" << cols_Left << endl;

    // double **mat = new double *[rows];

    // 2 Dimensional vector to store the left matrix
    vector<vector<double>> mat_Left(rows_Left, vector<double>(cols_Left));

    for (int i = 0; i < rows_Left; i++)
    {
        // mat[i] = new double[cols];
        for (int j = 0; j < cols_Left; j++)
        {
            Fin >> mat_Left[i][j];
        }
    }

    cout << "Left matrix is::" << FileName_L << ":\n";
    PrintMatrix(mat_Left);

    Fin.close();

    // Reading right matrix

    Fin.open(FileName_R);

    int rows_Right, cols_Right;
    Fin >> rows_Right >> cols_Right;
    cout << "\n rows::" << rows_Right << "\tcols::" << cols_Right << endl;

    vector<vector<double>> mat_Right(rows_Right, vector<double>(cols_Right));

    for (int i = 0; i < rows_Right; i++)
    {
        // Fin >> mat[i][cols - 1];
        for (int j = 0; j < cols_Right; j++)
        {
            Fin >> mat_Right[i][j];
        }
    }

    cout << "Right matrix is::" << FileName_R << ":\n";
    PrintMatrix(mat_Right);

    // cout << "Augmented matrix::";
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Check if rows of both matrices are same
    if (rows_Left != rows_Right)
    {
        cerr << "rows of left matrix is not equal to rows of right matrix" << endl;
        return 1;
    }

    // Augment the matrices
    vector<vector<double>> augmented_matrix(rows_Left, vector<double>(cols_Left + cols_Right));

    for (int i = 0; i < rows_Left; i++)
    {
        for (int j = 0; j < cols_Left; j++)
        {
            augmented_matrix[i][j] = mat_Left[i][j];
        }
        for (int j = 0; j < cols_Right; j++)
        {
            augmented_matrix[i][cols_Left + j] = mat_Right[i][j];
        }
    }

    // cout << "Augmented Matrix:\n";
    // PrintMatrix(augmented_matrix);

    return 0;
}
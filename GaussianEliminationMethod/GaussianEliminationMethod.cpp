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
    cout << "\n No of rows::" << rows_Left << "\tNo of cols::" << cols_Left << endl;

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
    cout << "\n No of rows::" << rows_Right << "\tNo of cols::" << cols_Right << endl;

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

    cout << "Given Augmented Matrix::\n";
    PrintMatrix(augmented_matrix);
    cout << endl;

    // reducing the matrix to upper triangular form
    for (int i = 0; i < rows_Left; i++)
    {
        // Step 1: Pivot Selection
        double pivot = augmented_matrix[i][i];

        // Step 2: Normalize Pivot Row
        for (int j = i; j < cols_Left + cols_Right; j++)
        {
            augmented_matrix[i][j] /= pivot;
        }

        // Step 3: Elimination
        for (int k = i + 1; k < rows_Left; k++)
        {
            double temp = augmented_matrix[k][i];
            for (int j = i; j < cols_Left + cols_Right; j++)
            {
                augmented_matrix[k][j] -= temp * augmented_matrix[i][j];
            }
        }

        PrintMatrix(augmented_matrix); // if i want to see the matrix after each iteration
        cout << endl;
    }

    cout << "Matrix in upper triangular form::\n";
    PrintMatrix(augmented_matrix);

    // back substitution

    vector<double> BackSubstitution(cols_Left);
    // BackSubstitution[cols_Left + cols_Right] = augmented_matrix[rows_Left + rows_Right - 1][cols_Left + cols_Right - 1];
    // cout << "Solution::" << endl;

    // Initialize BackSubstitution vector with zeros
    // for (int i = 0; i < cols_Left; ++i)
    // {
    //     BackSubstitution[i] = 0.0;
    // }

    for (int i = rows_Left - 1; i >= 0; --i)
    {
        //     double RHS = augmented_matrix[i][cols_Left]; // Right-hand side of the equation
        //     for (int j = i + 1; j < cols_Left; ++j)
        //     {
        //         RHS -= augmented_matrix[i][j] * BackSubstitution[j];
        //     }
        //     BackSubstitution[i] = RHS / augmented_matrix[i][i];
        //

        double sum = 0;
        for (int j = i + 1; j < cols_Left; ++j)
        {
            sum += augmented_matrix[i][j] * BackSubstitution[j];
        }
        BackSubstitution[i] = (augmented_matrix[i][cols_Left] - sum) / augmented_matrix[i][i];
    }

    cout << "Solution::" << endl;
    for (int i = 0; i < cols_Left; ++i)
    {
        cout << "x" << i + 1 << " = " << BackSubstitution[i] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#include<iostream>
#include <random>

using namespace std;

int n2 = 4;

void add(vector< vector<int> >& matrixA,vector< vector<int> >& matrixB,
    vector< vector<int> >& matrixC, unsigned int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
}

// subtract two matrices
void sub (vector< vector<int> >& matrixA,
    vector< vector<int> >& matrixB,
    vector< vector<int> >& matrixC, unsigned int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    
}
// In order to run this file only all you want to do is uncomment the code


// write matrix to output file


// print a matrix to the console
// void printMatrix(vector< vector<int> >& matrix, unsigned int matrixSize) {
//     for (int i = 0; i < matrixSize; i++) {
//         for (int j = 0; j < matrixSize; j++) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// recursive strassen matrix multiplier
void strassenR(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int matrixSize
) {

    // recursive base case
    if (matrixSize == 1) {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return ;
    }
    else {
        int newSize = matrixSize / 2;
        vector<int> innerVector(newSize, 0);

        // initialize matrices
        vector< vector<int> > a11(newSize, innerVector),
            a12(newSize, innerVector),
            a21(newSize, innerVector),
            a22(newSize, innerVector),
            b11(newSize, innerVector),
            b12(newSize, innerVector),
            b21(newSize, innerVector),
            b22(newSize, innerVector),
            c11(newSize, innerVector),
            c12(newSize, innerVector),
            c21(newSize, innerVector),
            c22(newSize, innerVector),
            s1(newSize, innerVector),
            s2(newSize, innerVector),
            s3(newSize, innerVector),
            s4(newSize, innerVector),
            s5(newSize, innerVector),
            s6(newSize, innerVector),
            s7(newSize, innerVector),
            s8(newSize, innerVector),
            s9(newSize, innerVector),
            s10(newSize, innerVector),
            p1(newSize, innerVector),
            p2(newSize, innerVector),
            p3(newSize, innerVector),
            p4(newSize, innerVector),
            p5(newSize, innerVector),
            p6(newSize, innerVector),
            p7(newSize, innerVector),
            tempMatrixA(newSize, innerVector),
            tempMatrixB(newSize, innerVector);

        // divide matrices into 4 submatrices
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                a11[i][j] = matrixA[i][j];
                a12[i][j] = matrixA[i][j + newSize];
                a21[i][j] = matrixA[i + newSize][j];
                a22[i][j] = matrixA[i + newSize][j + newSize];

                b11[i][j] = matrixB[i][j];
                b12[i][j] = matrixB[i][j + newSize];
                b21[i][j] = matrixB[i + newSize][j];
                b22[i][j] = matrixB[i + newSize][j + newSize];
            }
        }

        // s1 = b12 - b22
        sub(b12, b22, s1, newSize);

        // s2 = a11 + a12
        add(a11, a12, s2, newSize);

        // s3 = a21 + a22
        add(a21, a22, s3, newSize);

        // s4 = b21 - b11
        sub(b21, b11, s4, newSize);

        // s5 = a11 + a22
        add(a11, a22, s5, newSize);

        // s6 = b11 + b22
        add(b11, b22, s6, newSize);

        // s7 = a12 - a22
        sub(a12, a22, s7, newSize);

        // s8 = b21 + b22
        add(b21, b22, s8, newSize);

        // s9 = a11 - a21
        sub(a11, a21, s9, newSize);

        // s10 = b11 + b12
        add(b11, b12, s10, newSize);

        // p1 = a11 * s1
        strassenR(a11, s1, p1, newSize);

        // p2 = s2 * b22
        strassenR(s2, b22, p2, newSize);

        // p3 = s3 * b11
        strassenR(s3, b11, p3, newSize);

        // p4 = a22 * s4
        strassenR(a22, s4, p4, newSize);

        // p5 = s5 * s6
        strassenR(s5, s6, p5, newSize);

        // p6 = s7 * s8
        strassenR(s7, s8, p6, newSize);

        // p7 = s9 * s10
        strassenR(s9, s10, p7, newSize);

        // c11 = p5 + p4 - p2 + p6
        add(p5, p4, tempMatrixA, newSize); // p5 + p4
        add(tempMatrixA, p6, tempMatrixB, newSize); // (p5 + p4) + p6
        sub(tempMatrixB, p2, c11, newSize); // (p5 + p4 + p6) - p2

        // c12 = p1 + p2
        add(p1, p2, c12, newSize);

        // c21 = p3 + p4
        add(p3, p4, c21, newSize);

        // c22 = p5 + p1 - p3 + p7
        add(p5, p1, tempMatrixA, newSize); // p5 + p1
        sub(tempMatrixA, p3, tempMatrixB, newSize); // (p5 + p1) - p3
        sub(tempMatrixB, p7, c22, newSize); // (p5 + p1 - p3) - p7
        
        // group into c
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                matrixC[i][j] = c11[i][j];
                matrixC[i][j + newSize] = c12[i][j];
                matrixC[i + newSize][j] = c21[i][j];
                matrixC[i + newSize][j + newSize] = c22[i][j];
            }
        }
        
    }
}

// call recursive function
vector<vector<int>> strassen(vector<vector<int>> &a, vector<vector<int>> &b) {

    vector<vector<int>> c(n2, vector<int>(n2, 0));
    strassenR(a, b, c, n2);
    return c;

}

// vector<vector<int>> generate_random_vector()
// {
//     vector<vector<int>>m(matrixSize, vector<int>(matrixSize, 0));
//     for (int i = 0; i < matrixSize; i++) {
//         for (int j = 0; j < matrixSize; j++) {
//             m[i][j] = i+1;
//         }
//     }
//     return m;

// }       
     

// int main(int argc, char **argv)
// {   

//     unsigned int matrixSize = 4;
    
   

   
//     vector< vector<int> > matrixA = generate_random_vector();
//     vector< vector<int> > matrixB = generate_random_vector();

//     vector< vector<int> > matrixC(matrixSize, vector<int> (matrixSize, 0));
   

//     cout << endl << "INPUT MATRIX A" << endl;
//     printMatrix(matrixA, matrixSize);

//     cout << endl << "INPUT MATRIX B" << endl;
//     printMatrix(matrixB, matrixSize);

//     // run strassen matrix multiplication algorithm
//     matrixC = strassen(matrixA, matrixB);

//     cout << endl << "MATRIX C = A * B" << endl;
//     printMatrix(matrixC, matrixSize);

    

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

/**
 * implement the naive matrix multiplication algorithm
 * 
 * @param
 *  a --> a 2d vector
 *  b --> a 2d vector
 * 
 * @return
 * the result of a*b "matrix multiplcation"
*/

int n = 4;
vector<vector<int>> naive(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> result (n,vector<int>(n,0));
    
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            for(int k=0; k<n; k++){
                result[row][col] += a[row][k]*b[k][col];


                
            }
        }
    }
    return result;
    
}
//  to check this file only ----> uncomment the code
// void printMatrix(vector< vector<int> > &matrix, unsigned int mSize) {
//     for (int i = 0; i < mSize; i++) {
//         for (int j = 0; j < mSize; j++) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }






// vector<vector<int>> generate_random_vector()
// {
    
//     vector<vector<int>> randomVector(n,vector<int>(n,0));
//      for( int i = 0; i < n; i++){
//         for( int j = 0;  j < n; j++){
//             randomVector[i][j] = rand()%100;
//             }
//         }
//     return randomVector;    
    

// }
// int main(int argc, char **argv){


//     vector<vector<int>>a = generate_random_vector();

//     vector<vector<int>>b = generate_random_vector();

//     vector<vector<int>>result = naive(a,b);
//     printMatrix(a,n);
//     printMatrix(b,n);

//     printMatrix(result,n);

    
//     return 0;
// }








#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include "naive.cpp"
#include "strassen.cpp"

using namespace std;

int matrixSize = 128;

/**
 * generate 2 2d-vectors with fixed size 128*128 
 * 
 * @return
 *  a 2d vector with size 128*128 contains random numbers
 * 
 */
vector<vector<int>> generate_random_vector()
{
    vector<vector<int>>randomMatrix(matrixSize, vector<int>(matrixSize, 0));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            randomMatrix[i][j] = i+1;
        }
    }
    return randomMatrix;

}   

/**
 * driving stress test for both algorithms
 * 
 * generate 2 2d-vectors with fixed size 128*128
 * compare their output and runnig time
*/
int main(int argc, char **argv)
{

    while (true)
    {
        vector<vector<int>> a = generate_random_vector();
        vector<vector<int>> b = generate_random_vector();
        vector<vector<int>> naive_result;
        vector<vector<int>> strassen_result;

        auto naive_start = std::chrono::high_resolution_clock::now();
        // fill this line
        naive_result = naive(a, b);
        auto naive_finish = std::chrono::high_resolution_clock::now();

        auto strassen_start = std::chrono::high_resolution_clock::now();
        // fill this line
        strassen_result = strassen(a, b);
        auto strassen_finish = std::chrono::high_resolution_clock::now();

        auto naive_time = (naive_finish - naive_start).count();
        auto strassen_time = (strassen_finish - strassen_start).count();

        if (strassen_result == naive_result)
        {
            cout << "equivalent result ";
            cout << "naive_time ==> " << naive_time;
            cout << "strassen_time ==> " << strassen_time;
            cout << "performance enhancment ==>" << naive_time / strassen_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algortihms " << endl;
            // you may want to store your variables in a file to re-run the test on the same inputs;
            break;
        }
    }
    return 0;
}

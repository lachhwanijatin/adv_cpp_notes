#include "matrix_multiply.h"
#include <thread>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

// Helper function to print a matrix cleanly
int main() {
    vector<vector<int>> A(1000, vector<int>(100,1));
    vector<vector<int>> B(100, vector<int>(1000,1));
    
    
    auto start1 = std::chrono::steady_clock::now();
    vector<vector<int>> result1 = matrixMultiply(A, B);
    auto end1 = std::chrono::steady_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    cout << "Sequential Output Time Taken:"<<duration1.count()<<std::endl;
    // printMatrix(result1);


    auto start2 = std::chrono::steady_clock::now();
    vector<vector<int>> result2 = matrixMultiplyParallel(A, B);
    auto end2 = std::chrono::steady_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    cout << "Parallel Output:"<<duration2.count()<<std::endl;
    // printMatrix(result2);

    compare_results(result1, result2);
    std::cout<<"Parallelism Factor:" << duration1.count()*1.0L/duration2.count() <<" Hardware Concurrency: " << std::thread::hardware_concurrency() << std::endl;
    return 0;
}
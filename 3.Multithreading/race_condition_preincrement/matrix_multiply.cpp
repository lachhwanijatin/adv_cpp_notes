#include "matrix_multiply.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix)
{
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << (j < matrix[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < matrix.size() - 1 ? ", " : "");
    }
    cout << "]\n";
}

void compare_results(const vector<vector<int>>& A,const vector<vector<int>>& B)
{
    if(A.size()==B.size() && A.size()>0 && A[0].size()==B[0].size())
    {
        for (size_t i = 0; i < A.size(); ++i) {
            for (size_t j = 0; j < B[i].size(); ++j) {
                if(A[i][j] != B[i][j])
                {
                    std::cout << "A and B are not equal" << std::endl;
                    return;
                }
            }
        }
        std::cout << "A and B equal" << std::endl;
    }else {
        std::cout << "A and B are not equal and have different size" << std::endl;
    }
}

// Assuming the multiplication is possible; m*n, n*p matrix for given matrices

void determineElements(const std::vector<std::vector<int>> &a,const std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result, const int n, int row_start, int row_end, int col_start, int col_end)
{
    for(int i=row_start; i<row_end; i++)
    {
        for(int k=0; k<n; k++)
        {
            auto currenta = a[i][k];
            for(int j=col_start; j<col_end; j++)
            {
                result[i][j] += currenta*b[k][j];
            }
        }
    }
}

std::vector<std::vector<int>>  matrixMultiply(const std::vector<std::vector<int>> &a,const std::vector<std::vector<int>> &b)
{
    if (a.empty() || b.empty() || a[0].empty() || b[0].empty()) {
        return {}; 
    }
    if (a[0].size() != b.size()) {
        throw invalid_argument("Matrix inner dimensions must agree.");
    }

    int m = a.size();
    int n = b.size();
    int p = b[0].size();
    vector<vector<int>> result(m, vector<int>(p, 0));
    determineElements(a,b, result, n, 0, m, 0, p);
    return result;
}


std::vector<std::vector<int>>  matrixMultiplyParallel(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b)
{
    if (a.empty() || b.empty() || a[0].empty() || b[0].empty()) {
        return {}; 
    }
    if (a[0].size() != b.size()) {
        throw invalid_argument("Matrix inner dimensions must agree.");
    }

    int m = a.size();
    int n = b.size();
    int p = b[0].size();
    vector<vector<int>> result(m, vector<int>(p, 0));
    auto num_threads = std::thread::hardware_concurrency();
    if(!num_threads) num_threads=1;
    std::vector<std::thread> threads;
    threads.reserve(num_threads);
    for(int i=0; i<num_threads;i++)
    {
        threads.emplace_back(determineElements, a, b, std::ref(result), n, (i*m)/num_threads, ((i+1)*m)/num_threads, 0, p);
    }
    for(auto &th: threads) th.join();
    return result;
}
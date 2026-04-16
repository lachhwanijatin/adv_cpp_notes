#pragma once
#include <vector>

std::vector<std::vector<int>>  matrixMultiply(const std::vector<std::vector<int>>&,const std::vector<std::vector<int>>&);
std::vector<std::vector<int>>  matrixMultiplyParallel(const std::vector<std::vector<int>>&,const std::vector<std::vector<int>>&);
void compare_results(const std::vector<std::vector<int>>& A,const std::vector<std::vector<int>>& B);
void printMatrix(const std::vector<std::vector<int>>& matrix);
cmake_minimum_required(VERSION 3.28)
project(simplecalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} src/main.cpp calculator/src/calculator.cpp)
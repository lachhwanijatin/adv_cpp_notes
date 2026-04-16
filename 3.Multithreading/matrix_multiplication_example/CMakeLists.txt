cmake_minimum_required(VERSION 3.28)
project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(SOURCES
    main.cpp
    matrix_multiply.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
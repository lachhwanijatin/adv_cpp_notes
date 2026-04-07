cmake_minimum_required(VERSION 3.28)
project(stl_recap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

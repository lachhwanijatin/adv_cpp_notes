cmake_minimum_required(VERSION 3.28)
project(maths)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/maths.cpp
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
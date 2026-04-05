cmake_minimum_required(VERSION 3.28)
project(maths)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/maths.cpp
)

option(ADVANCED_API_ENABLE "THIS IS FOR THE ADVANCED API" ON)


add_library(${PROJECT_NAME} STATIC ${SOURCES})

if(ADVANCED_API_ENABLE)
    message("NOTE: ADVANCED_API_ENABLE is ENABLED")
    target_compile_definitions(${PROJECT_NAME} PUBLIC ADVANCED_API)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC include)
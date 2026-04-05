cmake_minimum_required(VERSION 3.28)
project(simplecalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.9.2
)

FetchContent_MakeAvailable(spdlog)

add_subdirectory(maths)
add_subdirectory(calculator)
add_subdirectory(physics)

set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE maths calculator physics)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

target_include_directories(${PROJECT_NAME} PRIVATE ${spdlog_SOURCE_DIR}/include)

# for more fine grained controlled over inclusion of external libraries view include(ExternalProject)
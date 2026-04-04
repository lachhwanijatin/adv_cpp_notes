cmake_minimum_required(VERSION 3.28)
project(physics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# forcing explicit visibility enablement for shared lib
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

SET(SOURCE 
    src/physics.cpp)

# SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
# SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
# SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_compile_definitions(${PROJECT_NAME} PRIVATE PHYSICS_EXPORT)

target_include_directories(${PROJECT_NAME} PUBLIC include)
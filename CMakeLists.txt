cmake_minimum_required(VERSION 3.20)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(MatrixFuck main.cpp src/Rational.h src/Support.h tests/tests.cpp src/Matrix.h DEBUG.h tests/matrix_test.cpp)
add_subdirectory(lib/gtest)
include_directories(lib/gtest/googletest/include src)
target_link_libraries(Matrix lib/gtest gtest_main)
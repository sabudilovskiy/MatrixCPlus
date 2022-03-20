cmake_minimum_required(VERSION 3.20)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix main.cpp src/Rational.h src/Support.h src/Matrix.h DEBUG.h src/Support.cpp tests/rational_tests.h tests/test.cpp)
add_subdirectory(lib/gtest)
include_directories(lib/gtest/googletest/include src)
target_link_libraries(Matrix gtest gtest_main)


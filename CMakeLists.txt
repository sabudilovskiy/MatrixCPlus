cmake_minimum_required(VERSION 3.20)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix
        main.cpp
        includes/Rational.h
        includes/Support.h
        includes/Matrix.h
        src/Support.tpp
        tests/test.cpp
        includes/Augmented_matrix.h
        includes/MathObject.h
        includes/Linear_space.h
        includes/Affine_space.h
        includes/Point.h
        includes/Point.h
        includes/Affine_space.h)
add_subdirectory(lib/gtest)
include_directories(lib/gtest/googletest/include
        src
        includes)
target_link_libraries(Matrix gtest gtest_main)


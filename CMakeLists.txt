cmake_minimum_required(VERSION 3.20)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix
        main.cpp
        src/Rational.h
        src/Support.h
        src/Matrix.h
        src/Support.tpp
        tests/test.cpp
        src/Augmented_matrix.h
        src/MathObject.h
        src/Linear_space.h
        src/Affine_space.h
        src/Point.h
        src/Point.h
        src/Affine_space.h)
add_subdirectory(lib/gtest)
include_directories(lib/gtest/googletest/include src)
target_link_libraries(Matrix gtest gtest_main)


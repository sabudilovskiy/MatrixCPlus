//
// Created by MRV on 20.03.2022.
//
#include "../DEBUG.h"
#ifdef DEBUG
#include "gtest/gtest.h"
#include "Rational.h"
#include "Matrix.h"
TEST(MatrixlTests, StringMatrixBasedTest)
{
    int n = 3;
    int m = 3;
    Rational** arr = new Rational*[m];
    for (int i = 0; i < m; i++){
        arr[i] = new Rational[n];
    }
    arr[0][0] = Rational(1,2);
    arr[0][1] = Rational(4,12);
    arr[0][2] = Rational(6,4);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(2,-3);
    arr[1][2] = Rational(3,5);
    arr[2][0] = Rational(4,5);
    arr[2][1] = Rational(4,8);
    arr[2][2] = Rational(3,6);
    Matrix<Rational> matrix(arr, 3, 3);
    std::string temp = matrix.to_string([](Rational rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "1/2 1/3 3/2 \n2 -2/3 3/5 \n4/5 1/2 1/2 \n");
}
TEST(MatrixlTests, StringMatrixPlusTest) {
    int n = 3;
    int m = 3;
    Rational** arr = new Rational*[m];
    Rational** arr_2 = new Rational*[m];
    for (int i = 0; i < m; i++){
        arr[i] = new Rational[n];
        arr_2[i] = new Rational[n];
    }
    arr[0][0] = Rational(1,2);
    arr[0][1] = Rational(4,12);
    arr[0][2] = Rational(6,4);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(2,-3);
    arr[1][2] = Rational(3,5);
    arr[2][0] = Rational(4,5);
    arr[2][1] = Rational(4,8);
    arr[2][2] = Rational(3,6);

    arr_2[0][0] = Rational(1,4);
    arr_2[0][1] = Rational(5,11);
    arr_2[0][2] = Rational(1,6);
    arr_2[1][0] = Rational(2,7);
    arr_2[1][1] = Rational(1,3);
    arr_2[1][2] = Rational(-3,5);
    arr_2[2][0] = Rational(4,5);
    arr_2[2][1] = Rational(3,4);
    arr_2[2][2] = Rational(1,2);
    Matrix<Rational> matrix(arr, 3, 3);
    Matrix<Rational> matrix_2(arr_2, 3, 3);
    std::string temp = (matrix+matrix_2).to_string([](Rational rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "3/4 26/33 5/3 \n16/7 -1/3 0 \n8/5 5/4 1 \n");
}
TEST(MatrixlTests, StringMatrixMinusTest) {
    int n = 3;
    int m = 3;
    Rational** arr = new Rational*[m];
    Rational** arr_2 = new Rational*[m];
    for (int i = 0; i < m; i++){
        arr[i] = new Rational[n];
        arr_2[i] = new Rational[n];
    }
    arr[0][0] = Rational(1,2);
    arr[0][1] = Rational(4,12);
    arr[0][2] = Rational(6,4);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(2,-3);
    arr[1][2] = Rational(3,5);
    arr[2][0] = Rational(4,5);
    arr[2][1] = Rational(4,8);
    arr[2][2] = Rational(3,6);

    arr_2[0][0] = Rational(1,4);
    arr_2[0][1] = Rational(5,11);
    arr_2[0][2] = Rational(1,6);
    arr_2[1][0] = Rational(2,7);
    arr_2[1][1] = Rational(1,3);
    arr_2[1][2] = Rational(-3,5);
    arr_2[2][0] = Rational(4,5);
    arr_2[2][1] = Rational(3,4);
    arr_2[2][2] = Rational(1,2);
    Matrix<Rational> matrix(arr, 3, 3);
    Matrix<Rational> matrix_2(arr_2, 3, 3);
    std::string temp = (matrix-matrix_2).to_string([](Rational rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "1/4 -4/33 4/3 \n12/7 -1 6/5 \n0 -1/4 0 \n");
}
TEST(MatrixlTests, StringMatrixMultTest) {
    int n = 3;
    int m = 3;
    Rational** arr = new Rational*[m];
    Rational** arr_2 = new Rational*[m];
    for (int i = 0; i < m; i++){
        arr[i] = new Rational[n];
        arr_2[i] = new Rational[n];
    }
    arr[0][0] = Rational(1,1);
    arr[0][1] = Rational(3,1);
    arr[0][2] = Rational(5,1);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(4,1);
    arr[1][2] = Rational(6,1);
    arr[2][0] = Rational(3,1);
    arr[2][1] = Rational(7,1);
    arr[2][2] = Rational(9,1);

    arr_2[0][0] = Rational(-3,2);
    arr_2[0][1] = Rational(2,1);
    arr_2[0][2] = Rational(-1,2);
    arr_2[1][0] = Rational(0,1);
    arr_2[1][1] = Rational(-3,2);
    arr_2[1][2] = Rational(1,1);
    arr_2[2][0] = Rational(1,2);
    arr_2[2][1] = Rational(1,2);
    arr_2[2][2] = Rational(-1,2);
    Matrix<Rational> matrix(arr, 3, 3);
    Matrix<Rational> matrix_2(arr_2, 3, 3);
    std::string temp = (matrix*matrix_2).to_string([](Rational rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "1 0 0 \n0 1 0 \n0 0 1 \n");
}

#endif
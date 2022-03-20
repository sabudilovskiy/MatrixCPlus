//
// Created by MRV on 20.03.2022.
//
#include "gtest/gtest.h"
#include "Matrix.h"
#include "Rational.h"
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
}
TEST(MatrixlTests, StringMatrixMinusTest) {
}
TEST(MatrixlTests, StringMatrixMultTest) {
}
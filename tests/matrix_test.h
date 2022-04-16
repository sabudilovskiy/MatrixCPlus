//
// Created by MRV on 20.03.2022.
//
#include "../DEBUG.h"
#ifdef DEBUG
#include "gtest/gtest.h"
#include "Rational.h"
#include "Matrix.h"
TEST(StringMatrixBasedTest, StringMatrixBasedTest)
{
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr;
    arr.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
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
    Matrix<Rational> matrix(arr);
    std::string temp = matrix.to_string([](const Rational& rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "1/2 1/3 3/2 \n2 -2/3 3/5 \n4/5 1/2 1/2 \n");
}
TEST(MatrixBasedOperationTest, StringMatrixPlusTest) {
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr;
    arr.resize(m);
    std::vector<std::vector<Rational>> arr_2;
    arr_2.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        arr_2[i].resize(n);
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
    Matrix<Rational> matrix(arr);
    Matrix<Rational> matrix_2(arr_2);
    std::string temp = (matrix+matrix_2).to_string([](const Rational& rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "3/4 26/33 5/3 \n16/7 -1/3 0 \n8/5 5/4 1 \n");
}
TEST(MatrixBasedOperationTest, StringMatrixMinusTest) {
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr;
    arr.resize(m);
    std::vector<std::vector<Rational>> arr_2;
    arr_2.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        arr_2[i].resize(n);
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
    Matrix<Rational> matrix(arr);
    Matrix<Rational> matrix_2(arr_2);
    std::string temp = (matrix-matrix_2).to_string([](const Rational& rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "1/4 -4/33 4/3 \n12/7 -1 6/5 \n0 -1/4 0 \n");
}
TEST(MatrixBasedOperationTest, StringMatrixMultTest) {
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr;
    arr.resize(m);
    std::vector<std::vector<Rational>> arr_2;
    arr_2.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        arr_2[i].resize(n);
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
    Matrix<Rational> matrix(arr);
    Matrix<Rational> matrix_2(arr_2);
    std::string temp = (matrix*matrix_2).to_string([](const Rational& rational) -> std::string { return rational.to_string();});
    EXPECT_EQ(temp , "1 0 0 \n0 1 0 \n0 0 1 \n");
}

class FictureMatrix : public ::testing::Test {
protected:
    Matrix<Rational> matrix1, matrix2;
    void SetUp() override{
        int n = 3;
        int m = 3;
        std::vector<std::vector<Rational>> arr;
        arr.resize(m);
        std::vector<std::vector<Rational>> arr_2;
        arr_2.resize(m);
        for (int i = 0; i < m; i++){
            arr[i].resize(n);
            arr_2[i].resize(n);
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
        matrix1 = Matrix(arr);
        matrix2 = Matrix(arr_2);
    }
    void TearDown() override{
    };

};

TEST_F(FictureMatrix, Test1){
    EXPECT_NO_THROW(matrix1.clear());
}
TEST_F(FictureMatrix, Test2){
    EXPECT_EQ(matrix1.get_m(), 3);
}
#endif
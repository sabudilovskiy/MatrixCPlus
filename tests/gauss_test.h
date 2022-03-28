#include "../DEBUG.h"
#ifdef DEBUG
#include "gtest/gtest.h"
#include "Rational.h"
#include "Matrix.h"
#include "Augmented_matrix.h"

TEST(MatrixGaussTest, UpTriangularTest){
    auto Stringer = [](const Rational& rational) -> std::string { return rational.to_string();};
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr;
    arr.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
    }
    arr[0][0] = Rational(1,1);
    arr[0][1] = Rational(3,1);
    arr[0][2] = Rational(4,1);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(4,1);
    arr[1][2] = Rational(6,1);
    arr[2][0] = Rational(3,1);
    arr[2][1] = Rational(7,1);
    arr[2][2] = Rational(9,1);
    Matrix<Rational> matrix1(arr);
    std::string temp = matrix1.triangular_transformation().to_string(Stringer);
    EXPECT_EQ(temp, "1 3 4 \n0 -2 -2 \n0 0 -1 \n");
}
TEST(MatrixGaussTest, GaussTest){
        auto Stringer = [](const Rational& rational) -> std::string { return rational.to_string();};
        int n = 3;
        int m = 3;
        std::vector<std::vector<Rational>> arr;
        arr.resize(m);
        for (int i = 0; i < m; i++){
            arr[i].resize(n);
        }
        arr[0][0] = Rational(1,1);
        arr[0][1] = Rational(3,1);
        arr[0][2] = Rational(4,1);
        arr[1][0] = Rational(2,1);
        arr[1][1] = Rational(4,1);
        arr[1][2] = Rational(6,1);
        arr[2][0] = Rational(3,1);
        arr[2][1] = Rational(7,1);
        arr[2][2] = Rational(9,1);
        Matrix<Rational> matrix1(arr);
        std::string temp = matrix1.gauss_transformation().to_string(Stringer);
        EXPECT_EQ(temp, "1 0 0 \n0 1 0 \n0 0 1 \n");
    }
TEST (MatrixGaussTest, SolveSystemTestPointZeros){
    auto Stringer = [](const Rational& rational) -> std::string { return rational.to_string();};
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr, aug_arr;
    arr.resize(m);
    aug_arr.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        aug_arr[i].resize(1);
    }
    arr[0][0] = Rational(1,1);
    arr[0][1] = Rational(3,1);
    arr[0][2] = Rational(4,1);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(4,1);
    arr[1][2] = Rational(6,1);
    arr[2][0] = Rational(3,1);
    arr[2][1] = Rational(7,1);
    arr[2][2] = Rational(9,1);
    aug_arr[0][0] = Rational(0);
    aug_arr[1][0]= Rational(0);
    aug_arr[2][0]= Rational(0);
    Augmented_matrix<Rational> matrix1(arr, aug_arr);
    MathObject<Rational>* answer = matrix1.solve_system();
    std::string temp = answer->to_string(Stringer);
    EXPECT_EQ(temp, "(0;0;0)");
}
TEST (MatrixGaussTest, SolveSystemTestPointNotZeros){
    auto Stringer = [](const Rational& rational) -> std::string { return rational.to_string();};
    int n = 3;
    int m = 3;
    std::vector<std::vector<Rational>> arr, aug_arr;
    arr.resize(m);
    aug_arr.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        aug_arr[i].resize(1);
    }
    arr[0][0] = Rational(1,1);
    arr[0][1] = Rational(3,1);
    arr[0][2] = Rational(4,1);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(4,1);
    arr[1][2] = Rational(6,1);
    arr[2][0] = Rational(3,1);
    arr[2][1] = Rational(7,1);
    arr[2][2] = Rational(9,1);
    aug_arr[0][0] = Rational(1);
    aug_arr[1][0]= Rational(2);
    aug_arr[2][0]= Rational(5);
    Augmented_matrix<Rational> matrix1(arr, aug_arr);
    MathObject<Rational>* answer = matrix1.solve_system();
    std::string temp = answer->to_string(Stringer);
    EXPECT_EQ(temp, "(3;2;-2)");
}
TEST (MatrixGaussTest, SolveSystemTestAffineSpace){
    auto Stringer = [](const Rational& rational) -> std::string { return rational.to_string();};
    int n = 3;
    int m = 2;
    std::vector<std::vector<Rational>> arr, aug_arr;
    arr.resize(m);
    aug_arr.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        aug_arr[i].resize(1);
    }
    arr[0][0] = Rational(1,1);
    arr[0][1] = Rational(3,1);
    arr[0][2] = Rational(4,1);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(4,1);
    arr[1][2] = Rational(6,1);
    aug_arr[0][0] = Rational(1);
    aug_arr[1][0]= Rational(2);
    Augmented_matrix<Rational> matrix1(arr, aug_arr);
    MathObject<Rational>* answer = matrix1.solve_system();
    std::string temp = answer->to_string(Stringer);
    EXPECT_EQ(temp, "Афинное пространство: \n v0 = (1 0 0)\nv1 = (-1 -1 1)\n");
}
TEST (MatrixGaussTest, SolveSystemTestLinearSpace){
    auto Stringer = [](const Rational& rational) -> std::string { return rational.to_string();};
    int n = 3;
    int m = 2;
    std::vector<std::vector<Rational>> arr, aug_arr;
    arr.resize(m);
    aug_arr.resize(m);
    for (int i = 0; i < m; i++){
        arr[i].resize(n);
        aug_arr[i].resize(1);
    }
    arr[0][0] = Rational(1,1);
    arr[0][1] = Rational(3,1);
    arr[0][2] = Rational(4,1);
    arr[1][0] = Rational(2,1);
    arr[1][1] = Rational(4,1);
    arr[1][2] = Rational(6,1);
    aug_arr[0][0] = Rational(0);
    aug_arr[1][0]= Rational(0);
    Augmented_matrix<Rational> matrix1(arr, aug_arr);
    MathObject<Rational>* answer = matrix1.solve_system();
    std::string temp = answer->to_string(Stringer);
    EXPECT_EQ(temp, "Линейное пространство: \nv1 = (-1 -1 1)\n");
}
#endif
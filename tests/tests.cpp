//
// Created by MRV on 20.03.2022.
//
#include "../DEBUG.h"
#ifdef DEBUG
#ifndef RATIONAL_TEST_MATRIX_FUCK
#define RATIONAL_TEST_MATRIX_FUCK
#include "Rational.h"
#include "gtest/gtest.h"
#include "Matrix.h"


TEST(RationalTests, StringBasedTest) {
    EXPECT_EQ(Rational(1,2).to_string(), "1/2");
}
TEST(RationalTests, StringPlusTest) {
    EXPECT_EQ((Rational(1,2) + Rational(1,2)).to_string(), "1");
    EXPECT_EQ((Rational(2,9) + Rational(1,3)).to_string(), "5/9");
}
TEST(RationalTests, StringMinusTest) {
    EXPECT_EQ((Rational(2,9) - Rational(1,3)).to_string(), "-1/9");
    EXPECT_EQ((Rational(5,4) - Rational(1,2)).to_string(), "3/4");
}
TEST(RationalTests, StringMultTest) {
    EXPECT_EQ((Rational(2,9) * Rational(1,3)).to_string(), "2/27");
    EXPECT_EQ((Rational(5,4) * Rational(4,10)).to_string(), "1/2");
}
TEST(RationalTests, StringDivTest) {
    EXPECT_EQ((Rational(2,9) / Rational(1,3)).to_string(), "2/3");
    EXPECT_EQ((Rational(5,4) / Rational(4,10)).to_string(), "25/8");
    Matrix<int> matrix;
}

#endif
#endif
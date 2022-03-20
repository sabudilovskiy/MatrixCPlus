#include "../DEBUG.h"
#ifdef DEBUG
#include "gtest/gtest.h"
#include "Rational.h"
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
}
#endif
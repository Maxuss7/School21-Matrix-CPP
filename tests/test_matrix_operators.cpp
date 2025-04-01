#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// Test suite: S21MatrixOperatorTest

TEST(S21MatrixOperatorTest, OperatorPlusAddsMatrices) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = 1.0;
  b(0, 0) = 2.0;
  S21Matrix c = a + b;
  EXPECT_DOUBLE_EQ(c(0, 0), 3.0);
}

TEST(S21MatrixOperatorTest, OperatorMinusValidCase) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = 3.0;
  b(0, 0) = 1.0;
  S21Matrix c = a - b;
  EXPECT_DOUBLE_EQ(c(0, 0), 2.0);
}

TEST(S21MatrixOperatorTest, OperatorMinusSubtractsMatrices) {
  S21Matrix a(2, 2), b(2, 2);
  a(1, 1) = 5.0;
  b(1, 1) = 3.0;
  S21Matrix c = a - b;
  EXPECT_DOUBLE_EQ(c(1, 1), 2.0);
}

TEST(S21MatrixOperatorTest, OperatorMulMatrixMultipliesMatrices) {
  S21Matrix a(2, 3), b(3, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 5;
  a(1, 2) = 6;
  b(0, 0) = 7;
  b(0, 1) = 8;
  b(1, 0) = 9;
  b(1, 1) = 10;
  b(2, 0) = 11;
  b(2, 1) = 12;
  S21Matrix c = a * b;
  EXPECT_DOUBLE_EQ(c(0, 0), 58);
  EXPECT_DOUBLE_EQ(c(1, 1), 154);
}

TEST(S21MatrixOperatorTest, OperatorMulNumberScalesMatrix) {
  S21Matrix m(2, 2);
  m(0, 1) = 3.0;
  S21Matrix c = m * 2.0;
  EXPECT_DOUBLE_EQ(c(0, 1), 6.0);
}

TEST(S21MatrixOperatorTest, OperatorEqualComparesMatrices) {
  S21Matrix a(2, 2), b(2, 2);
  a(1, 1) = b(1, 1) = 4.4;
  EXPECT_TRUE(a == b);
  b(0, 0) = 1.1;
  EXPECT_FALSE(a == b);
}

TEST(S21MatrixOperatorTest, OperatorCompoundPlusAdds) {
  S21Matrix a(1, 1), b(1, 1);
  b(0, 0) = 5.5;
  a += b;
  EXPECT_DOUBLE_EQ(a(0, 0), 5.5);
}

TEST(S21MatrixOperatorTest, OperatorCompoundMinusSubtracts) {
  S21Matrix a(1, 1), b(1, 1);
  a(0, 0) = 7.7;
  b(0, 0) = 2.2;
  a -= b;
  EXPECT_DOUBLE_EQ(a(0, 0), 5.5);
}

TEST(S21MatrixOperatorTest, OperatorCompoundMulMatrix) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = 1;
  a(1, 1) = 1;
  b(0, 0) = 2;
  b(1, 1) = 3;
  a *= b;
  EXPECT_DOUBLE_EQ(a(0, 0), 2);
  EXPECT_DOUBLE_EQ(a(1, 1), 3);
}

TEST(S21MatrixOperatorTest, OperatorCompoundMulNumber) {
  S21Matrix a(2, 2);
  a(0, 1) = 2.0;
  a *= 3.0;
  EXPECT_DOUBLE_EQ(a(0, 1), 6.0);
}

TEST(S21MatrixOperatorTest, OperatorParenthesesAccess) {
  S21Matrix m(2, 2);
  m(0, 1) = 1.23;
  EXPECT_DOUBLE_EQ(m(0, 1), 1.23);
  const S21Matrix& cm = m;
  EXPECT_DOUBLE_EQ(cm(0, 1), 1.23);
}

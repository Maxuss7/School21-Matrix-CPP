#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(Operator, Addition) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  B(0, 0) = 2;
  S21Matrix C = A + B;
  EXPECT_DOUBLE_EQ(C(0, 0), 3);
}

TEST(Operator, Subtraction) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 5;
  B(0, 0) = 3;
  S21Matrix C = A - B;
  EXPECT_DOUBLE_EQ(C(0, 0), 2);
}

TEST(Operator, MultiplyMatrix) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  B(0, 0) = 3;
  B(1, 0) = 4;
  S21Matrix C = A * B;
  EXPECT_DOUBLE_EQ(C(0, 0), 11);
}

TEST(Operator, MultiplyNumberLeft) {
  S21Matrix A(2, 2);
  A(0, 0) = 3;
  S21Matrix B = A * 2.0;
  EXPECT_DOUBLE_EQ(B(0, 0), 6);
}

TEST(Operator, MultiplyNumberRight) {
  S21Matrix A(2, 2);
  A(0, 0) = 3;
  S21Matrix B = 2.0 * A;
  EXPECT_DOUBLE_EQ(B(0, 0), 6);
}

TEST(Operator, EqualityTrue) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  B(0, 0) = 1;
  EXPECT_TRUE(A == B);
}

TEST(Operator, EqualityFalse) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  B(0, 0) = 2;
  EXPECT_FALSE(A == B);
}

TEST(Operator, AssignmentCopy) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  S21Matrix B;
  B = A;
  EXPECT_DOUBLE_EQ(B(0, 0), 1);
}

TEST(Operator, AssignmentMove) {
  S21Matrix A(2, 2);
  A(0, 0) = 7;
  S21Matrix B = std::move(A);
  EXPECT_DOUBLE_EQ(B(0, 0), 7);
}

TEST(Operator, PlusEqual) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 2;
  B(0, 0) = 3;
  A += B;
  EXPECT_DOUBLE_EQ(A(0, 0), 5);
}

TEST(Operator, MinusEqual) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 5;
  B(0, 0) = 2;
  A -= B;
  EXPECT_DOUBLE_EQ(A(0, 0), 3);
}

TEST(Operator, MultiplyEqualMatrix) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  B(0, 0) = 3;
  B(1, 0) = 4;
  A *= B;
  EXPECT_DOUBLE_EQ(A(0, 0), 11);
}

TEST(Operator, MultiplyEqualNumber) {
  S21Matrix A(2, 2);
  A(0, 0) = 5;
  A *= 2;
  EXPECT_DOUBLE_EQ(A(0, 0), 10);
}

TEST(Operator, Indexing) {
  S21Matrix A(2, 2);
  A(1, 1) = 42;
  EXPECT_DOUBLE_EQ(A(1, 1), 42);
}

TEST(Operator, IndexingOutOfBounds) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(2, 2), std::out_of_range);
}

TEST(Operator, Indexing_ReadWrite) {
  S21Matrix A(2, 2);
  A(0, 1) = 3.14;
  EXPECT_DOUBLE_EQ(A(0, 1), 3.14);
}

TEST(Operator, Indexing_ConstAccess) {
  S21Matrix A(2, 2);
  A(1, 1) = 42.0;
  const S21Matrix B = A;
  EXPECT_DOUBLE_EQ(B(1, 1), 42.0);
}

TEST(Operator, OperatorIndex_BranchReturnOk) {
  S21Matrix A(2, 2);
  A(0, 1) = 42.0;
  EXPECT_DOUBLE_EQ(A(0, 1), 42.0);  // проходит условие, НЕ вызывает throw
}

TEST(Operator, ConstOperatorIndex_BranchReturnOk) {
  S21Matrix A(2, 2);
  A(1, 0) = 3.14;
  const S21Matrix B = A;
  EXPECT_DOUBLE_EQ(B(1, 0), 3.14);  // тоже не вызывает throw
}

TEST(Exception, InverseMatrix1x1_Zero) {
  S21Matrix A(1, 1);
  A(0, 0) = 0.0;
  EXPECT_THROW(A.InverseMatrix(), std::logic_error);
}

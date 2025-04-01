#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// Test suite: S21MatrixExceptionTest

TEST(S21MatrixExceptionTest, ConstructorThrowsOnInvalidSize) {
  EXPECT_THROW(S21Matrix(-5, 5), std::invalid_argument);
  EXPECT_THROW(S21Matrix(5, 0), std::invalid_argument);
  EXPECT_THROW(S21Matrix(0, 0), std::invalid_argument);
  EXPECT_NO_THROW(S21Matrix(3, 3));
}

TEST(S21MatrixExceptionTest, SetRowsThrowsOnZeroOrNegative) {
  S21Matrix m(3, 3);
  EXPECT_THROW(m.SetRows(0), std::invalid_argument);
  EXPECT_THROW(m.SetRows(-2), std::invalid_argument);
  EXPECT_NO_THROW(m.SetRows(2));
}

TEST(S21MatrixExceptionTest, SetColsThrowsOnZeroOrNegative) {
  S21Matrix m(3, 3);
  EXPECT_THROW(m.SetCols(0), std::invalid_argument);
  EXPECT_THROW(m.SetCols(-1), std::invalid_argument);
  EXPECT_NO_THROW(m.SetCols(2));
}

TEST(S21MatrixExceptionTest, OperatorAccessThrowsOnOutOfRange) {
  S21Matrix m(2, 2);
  EXPECT_THROW(m(-1, 0), std::out_of_range);
  EXPECT_THROW(m(0, -1), std::out_of_range);
  EXPECT_THROW(m(2, 0), std::out_of_range);
  EXPECT_THROW(m(0, 2), std::out_of_range);
  EXPECT_NO_THROW(m(1, 1));
}

TEST(S21MatrixExceptionTest, SumMatrixThrowsOnMismatchedDimensions) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 3);
  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
  S21Matrix m3(2, 2);
  EXPECT_NO_THROW(m1.SumMatrix(m3));
}

TEST(S21MatrixExceptionTest, SubMatrixThrowsOnMismatchedDimensions) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 3);
  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
  S21Matrix m3(2, 2);
  EXPECT_NO_THROW(m1.SubMatrix(m3));
}

TEST(S21MatrixExceptionTest, MulMatrixThrowsOnInvalidDimensions) {
  S21Matrix m1(2, 3);
  S21Matrix m2(2, 2);
  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
  S21Matrix m3(3, 4);
  EXPECT_NO_THROW(m1.MulMatrix(m3));
}

TEST(S21MatrixExceptionTest, DeterminantThrowsOnNonSquare) {
  S21Matrix m(2, 3);
  EXPECT_THROW(m.Determinant(), std::logic_error);
  S21Matrix m2(3, 3);
  EXPECT_NO_THROW(m2.Determinant());
}

TEST(S21MatrixExceptionTest, CalcComplementsThrowsOnNonSquare) {
  S21Matrix m(3, 2);
  EXPECT_THROW(m.CalcComplements(), std::logic_error);
  S21Matrix m2(3, 3);
  EXPECT_NO_THROW(m2.CalcComplements());
}

TEST(S21MatrixExceptionTest, InverseMatrixThrowsOnZeroDeterminant) {
  S21Matrix m(2, 2);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 2;
  m(1, 1) = 4;  
  EXPECT_THROW(m.InverseMatrix(), std::logic_error);
  S21Matrix m2(2, 2);
  m2(0, 0) = 4;
  m2(0, 1) = 7;
  m2(1, 0) = 2;
  m2(1, 1) = 6;
  EXPECT_NO_THROW(m2.InverseMatrix());
}

TEST(S21OperatorExceptionTest, ConstOperatorAccessThrowsOutOfRange) {
  const S21Matrix m(2, 2);
  EXPECT_THROW(m(5, 5), std::out_of_range);
}

TEST(S21OperatorExceptionTest, ConstOperatorOutOfRangeAccess) {
  const S21Matrix m(2, 2);
  EXPECT_THROW(m(2, 2), std::out_of_range);
}

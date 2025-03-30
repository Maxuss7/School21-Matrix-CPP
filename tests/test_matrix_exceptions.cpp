#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(Exception, Constructor_InvalidSize) {
  EXPECT_THROW(S21Matrix A(-1, 2), std::invalid_argument);
  EXPECT_THROW(S21Matrix B(0, 0), std::invalid_argument);
}

TEST(Exception, SetRows_Invalid) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A.SetRows(0), std::invalid_argument);
}

TEST(Exception, SetCols_Invalid) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A.SetCols(-3), std::invalid_argument);
}

TEST(Exception, SumMatrix_DifferentSizes) {
  S21Matrix A(2, 2), B(3, 3);
  EXPECT_THROW(A.SumMatrix(B), std::invalid_argument);
}

TEST(Exception, SubMatrix_DifferentSizes) {
  S21Matrix A(2, 2), B(1, 1);
  EXPECT_THROW(A.SubMatrix(B), std::invalid_argument);
}

TEST(Exception, MulMatrix_IncompatibleSizes) {
  S21Matrix A(2, 3), B(2, 2);
  EXPECT_THROW(A.MulMatrix(B), std::invalid_argument);
}

TEST(Exception, Index_OutOfBounds) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(3, 0), std::out_of_range);
  EXPECT_THROW(A(-1, 0), std::out_of_range);
  EXPECT_THROW(A(1, 5), std::out_of_range);
}

TEST(Exception, Determinant_NotSquare) {
  S21Matrix A(2, 3);
  EXPECT_THROW(A.Determinant(), std::logic_error);
}

TEST(Exception, CalcComplements_NotSquare) {
  S21Matrix A(2, 3);
  EXPECT_THROW(A.CalcComplements(), std::logic_error);
}

TEST(Exception, InverseMatrix_Singular) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 2;
  A(1, 1) = 4;  // det = 0
  EXPECT_THROW(A.InverseMatrix(), std::logic_error);
}

TEST(Exception, ConstIndex_OutOfBounds) {
  const S21Matrix A(2, 2);
  EXPECT_THROW(A(2, 0), std::out_of_range);
  EXPECT_THROW(A(0, 2), std::out_of_range);
  EXPECT_THROW(A(-1, 1), std::out_of_range);
}

TEST(Exception, SetRows_Shrink_CopyContent) {
  S21Matrix A(3, 2);
  A(2, 1) = 9.99;
  A.SetRows(2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_THROW(A(2, 1), std::out_of_range);
}

TEST(Exception, SetCols_Shrink_CopyContent) {
  S21Matrix A(2, 3);
  A(1, 2) = 7.77;
  A.SetCols(2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_THROW(A(1, 2), std::out_of_range);
}

TEST(Exception, Index_OutOfBounds_AllPaths) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(-1, 0), std::out_of_range);
  EXPECT_THROW(A(2, 0), std::out_of_range);
  EXPECT_THROW(A(0, -1), std::out_of_range);
  EXPECT_THROW(A(0, 2), std::out_of_range);
}

TEST(Exception, ConstIndex_OutOfBounds_AllPaths) {
  const S21Matrix A(2, 2);
  EXPECT_THROW(A(-1, 0), std::out_of_range);
  EXPECT_THROW(A(2, 0), std::out_of_range);
  EXPECT_THROW(A(0, -1), std::out_of_range);
  EXPECT_THROW(A(0, 2), std::out_of_range);
}

TEST(Exception, Operator_Index_RowTooLow) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(-1, 1), std::out_of_range);
}

TEST(Exception, Operator_Index_RowTooHigh) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(2, 1), std::out_of_range);
}

TEST(Exception, Operator_Index_ColTooLow) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(1, -1), std::out_of_range);
}

TEST(Exception, Operator_Index_ColTooHigh) {
  S21Matrix A(2, 2);
  EXPECT_THROW(A(1, 2), std::out_of_range);
}

TEST(Exception, Operator_ConstIndex_ColTooHigh) {
  const S21Matrix A(2, 2);
  EXPECT_THROW(A(1, 2), std::out_of_range);
}

TEST(Exception, OperatorAdd_DimensionsMismatch) {
  S21Matrix A(2, 2), B(3, 3);
  EXPECT_THROW(A + B, std::invalid_argument);
}

TEST(Exception, OperatorSub_DimensionsMismatch) {
  S21Matrix A(2, 2), B(3, 3);
  EXPECT_THROW(A - B, std::invalid_argument);
}

TEST(Exception, OperatorMul_DimensionsMismatch) {
  S21Matrix A(2, 3), B(2, 2);
  EXPECT_THROW(A * B, std::invalid_argument);
}

TEST(Exception, InverseMatrix_NearlySingularMatrix) {
  S21Matrix A(2, 2);
  A(0, 0) = 1e-9;
  A(0, 1) = 0.0;
  A(1, 0) = 0.0;
  A(1, 1) = 1e-9;
  EXPECT_THROW(A.InverseMatrix(), std::logic_error);
}

TEST(Exception, InverseMatrix1x1_ZeroDeterminant) {
  S21Matrix A(1, 1);
  A(0, 0) = 0.0;
  EXPECT_THROW(A.InverseMatrix(), std::logic_error);
}

TEST(Exception, InverseMatrix_2x2_NearlyZeroDeterminant) {
  S21Matrix A(2, 2);
  A(0, 0) = 1e-8;
  A(0, 1) = 0;
  A(1, 0) = 0;
  A(1, 1) = 1e-8;
  EXPECT_THROW(A.InverseMatrix(), std::logic_error);
}
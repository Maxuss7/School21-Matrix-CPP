#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// Test suite: S21MatrixMethodTest

TEST(S21MatrixMethodTest, SetRowsIncreasesSize) {
  S21Matrix m(2, 2);
  m(0, 0) = 1.0;
  EXPECT_NO_THROW(m.SetRows(3));
  EXPECT_DOUBLE_EQ(m(0, 0), 1.0);  
}

TEST(S21MatrixMethodTest, SetColsIncreasesSize) {
  S21Matrix m(2, 2);
  m(0, 1) = 2.0;
  EXPECT_NO_THROW(m.SetCols(3));
  EXPECT_DOUBLE_EQ(m(0, 1), 2.0); 
}

TEST(S21MatrixMethodTest, EqMatrixReturnsTrueForIdentical) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = b(0, 0) = 1.1;
  a(1, 1) = b(1, 1) = 2.2;
  EXPECT_TRUE(a.EqMatrix(b));
}

TEST(S21MatrixMethodTest, EqMatrixReturnsFalseForDifferent) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = 1.0;
  b(0, 0) = 2.0;
  EXPECT_FALSE(a.EqMatrix(b));
}

TEST(S21MatrixMethodTest, SumMatrixAddsCorrectly) {
  S21Matrix a(2, 2), b(2, 2);
  a(0, 0) = 1.0;
  b(0, 0) = 2.0;
  a.SumMatrix(b);
  EXPECT_DOUBLE_EQ(a(0, 0), 3.0);
}

TEST(S21MatrixMethodTest, SubMatrixSubtractsCorrectly) {
  S21Matrix a(2, 2), b(2, 2);
  a(1, 1) = 5.0;
  b(1, 1) = 3.0;
  a.SubMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), 2.0);
}

TEST(S21MatrixMethodTest, MulNumberScalesMatrix) {
  S21Matrix m(2, 2);
  m(0, 0) = 2.0;
  m.MulNumber(3.0);
  EXPECT_DOUBLE_EQ(m(0, 0), 6.0);
}

TEST(S21MatrixMethodTest, MulMatrixCalculatesProductCorrectly) {
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
  a.MulMatrix(b);
  EXPECT_DOUBLE_EQ(a(0, 0), 58.0);
  EXPECT_DOUBLE_EQ(a(0, 1), 64.0);
  EXPECT_DOUBLE_EQ(a(1, 0), 139.0);
  EXPECT_DOUBLE_EQ(a(1, 1), 154.0);
}

TEST(S21MatrixMethodTest, TransposeFlipsMatrix) {
  S21Matrix m(2, 3);
  m(0, 1) = 5.5;
  S21Matrix t = m.Transpose();
  EXPECT_EQ(t.GetRows(), 3);
  EXPECT_EQ(t.GetCols(), 2);
  EXPECT_DOUBLE_EQ(t(1, 0), 5.5);
}

TEST(S21MatrixMethodTest, DeterminantFor2x2) {
  S21Matrix m(2, 2);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;
  EXPECT_DOUBLE_EQ(m.Determinant(), -2);
}

TEST(S21MatrixMethodTest, DeterminantFor3x3) {
  S21Matrix m(3, 3);
  m(0, 0) = 6;
  m(0, 1) = 1;
  m(0, 2) = 1;
  m(1, 0) = 4;
  m(1, 1) = -2;
  m(1, 2) = 5;
  m(2, 0) = 2;
  m(2, 1) = 8;
  m(2, 2) = 7;
  EXPECT_DOUBLE_EQ(m.Determinant(), -306);
}

TEST(S21MatrixMethodTest, CalcComplementsFor2x2) {
  S21Matrix m(2, 2);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;
  S21Matrix c = m.CalcComplements();
  EXPECT_DOUBLE_EQ(c(0, 0), 4);
  EXPECT_DOUBLE_EQ(c(0, 1), -3);
  EXPECT_DOUBLE_EQ(c(1, 0), -2);
  EXPECT_DOUBLE_EQ(c(1, 1), 1);
}

TEST(S21MatrixMethodTest, InverseMatrixFor2x2) {
  S21Matrix m(2, 2);
  m(0, 0) = 4;
  m(0, 1) = 7;
  m(1, 0) = 2;
  m(1, 1) = 6;
  S21Matrix inv = m.InverseMatrix();
  EXPECT_NEAR(inv(0, 0), 0.6, 1e-7);
  EXPECT_NEAR(inv(0, 1), -0.7, 1e-7);
  EXPECT_NEAR(inv(1, 0), -0.2, 1e-7);
  EXPECT_NEAR(inv(1, 1), 0.4, 1e-7);
}

TEST(S21MatrixMethodTest, InverseMatrixFor1x1) {
  S21Matrix m(1, 1);
  m(0, 0) = 4.0;
  S21Matrix inv = m.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv(0, 0), 0.25);
}

TEST(S21MatrixMethodTest, CalcComplementsFor1x1) {
  S21Matrix m(1, 1);
  m(0, 0) = 42.0;
  S21Matrix c = m.CalcComplements();
  EXPECT_EQ(c.GetRows(), 1);
  EXPECT_EQ(c.GetCols(), 1);
  EXPECT_DOUBLE_EQ(c(0, 0), 1.0);
}

TEST(S21MatrixMethodTest, CalcComplementsFor3x3) {
  S21Matrix m(3, 3);
  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 0;
  m(1, 1) = 4;
  m(1, 2) = 5;
  m(2, 0) = 1;
  m(2, 1) = 0;
  m(2, 2) = 6;
  S21Matrix c = m.CalcComplements();
  EXPECT_DOUBLE_EQ(c(0, 0), 24.0);
  EXPECT_DOUBLE_EQ(c(0, 1), 5.0);
  EXPECT_DOUBLE_EQ(c(0, 2), -4.0);
}

TEST(S21MatrixMethodTest, InverseMatrixFor1x1ThrowsOnZero) {
  S21Matrix m(1, 1);
  m(0, 0) = 0.0;
  EXPECT_THROW(m.InverseMatrix(), std::logic_error);
}

TEST(S21MatrixMethodTest, MulMatrixSingleElement) {
  S21Matrix a(1, 1), b(1, 1);
  a(0, 0) = 2.0;
  b(0, 0) = 3.0;
  a.MulMatrix(b);
  EXPECT_DOUBLE_EQ(a(0, 0), 6.0);
}

TEST(S21MatrixMethodTest, DeterminantWithNegativeMinor) {
  S21Matrix m(3, 3);
  m(0, 0) = 2;
  m(0, 1) = 0;
  m(0, 2) = 1;
  m(1, 0) = 3;
  m(1, 1) = 0;
  m(1, 2) = 0;
  m(2, 0) = 5;
  m(2, 1) = 1;
  m(2, 2) = 1;
  EXPECT_NE(m.Determinant(), 0.0);  
}

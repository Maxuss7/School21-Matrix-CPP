#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// === SumMatrix ===
TEST(Method, SumMatrix1) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  B(0, 0) = 2;
  A.SumMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 0), 3);
}

TEST(Method, SumMatrix2) {
  S21Matrix A(1, 1), B(1, 1);
  A(0, 0) = 5;
  B(0, 0) = -3;
  A.SumMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 0), 2);
}

TEST(Method, SumMatrix3) {
  S21Matrix A(3, 3), B(3, 3);
  A(1, 1) = 2;
  B(1, 1) = 3;
  A.SumMatrix(B);
  EXPECT_DOUBLE_EQ(A(1, 1), 5);
}

TEST(Method, SumMatrix4) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 1) = 1.5;
  B(0, 1) = 2.5;
  A.SumMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 1), 4);
}

TEST(Method, SumMatrix5) {
  S21Matrix A(2, 2), B(2, 2);
  A(1, 0) = -1;
  B(1, 0) = 1;
  A.SumMatrix(B);
  EXPECT_DOUBLE_EQ(A(1, 0), 0);
}

// === SubMatrix ===
TEST(Method, SubMatrix1) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 5;
  B(0, 0) = 2;
  A.SubMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 0), 3);
}

TEST(Method, SubMatrix2) {
  S21Matrix A(1, 1), B(1, 1);
  A(0, 0) = -2;
  B(0, 0) = -3;
  A.SubMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 0), 1);
}

TEST(Method, SubMatrix3) {
  S21Matrix A(2, 2), B(2, 2);
  A(1, 1) = 6;
  B(1, 1) = 1;
  A.SubMatrix(B);
  EXPECT_DOUBLE_EQ(A(1, 1), 5);
}

TEST(Method, SubMatrix4) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 1) = 3.5;
  B(0, 1) = 1.5;
  A.SubMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 1), 2.0);
}

TEST(Method, SubMatrix5) {
  S21Matrix A(2, 2), B(2, 2);
  A(1, 0) = 7;
  B(1, 0) = 10;
  A.SubMatrix(B);
  EXPECT_DOUBLE_EQ(A(1, 0), -3);
}

// === MulNumber ===
TEST(Method, MulNumber1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3;
  A.MulNumber(2);
  EXPECT_DOUBLE_EQ(A(0, 0), 6);
}

TEST(Method, MulNumber2) {
  S21Matrix A(1, 1);
  A(0, 0) = -5;
  A.MulNumber(-1);
  EXPECT_DOUBLE_EQ(A(0, 0), 5);
}

TEST(Method, MulNumber3) {
  S21Matrix A(2, 2);
  A(0, 1) = 2.5;
  A.MulNumber(2);
  EXPECT_DOUBLE_EQ(A(0, 1), 5);
}

TEST(Method, MulNumber4) {
  S21Matrix A(2, 2);
  A(1, 0) = 0;
  A.MulNumber(123);
  EXPECT_DOUBLE_EQ(A(1, 0), 0);
}

TEST(Method, MulNumber5) {
  S21Matrix A(2, 2);
  A(1, 1) = 1.5;
  A.MulNumber(0.5);
  EXPECT_NEAR(A(1, 1), 0.75, 1e-7);
}

TEST(Method, MulMatrix1) {
  S21Matrix A(2, 3), B(3, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  B(0, 0) = 4;
  B(1, 0) = 5;
  B(2, 0) = 6;
  A.MulMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 0), 32);
}

TEST(Method, MulMatrix2) {
  S21Matrix A(1, 3), B(3, 1);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  B(0, 0) = 4;
  B(1, 0) = 5;
  B(2, 0) = 6;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetRows(), 1);
  EXPECT_EQ(A.GetCols(), 1);
  EXPECT_DOUBLE_EQ(A(0, 0), 32);
}

TEST(Method, MulMatrix3) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  A(1, 1) = 1;
  B(0, 0) = 5;
  B(1, 1) = 5;
  A.MulMatrix(B);
  EXPECT_DOUBLE_EQ(A(0, 0), 5);
  EXPECT_DOUBLE_EQ(A(1, 1), 5);
}

TEST(Method, MulMatrix4) {
  S21Matrix A(2, 2), B(2, 1);
  A(0, 0) = 2;
  A(1, 1) = 3;
  B(0, 0) = 4;
  B(1, 0) = 5;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetCols(), 1);
  EXPECT_DOUBLE_EQ(A(0, 0), 8);
  EXPECT_DOUBLE_EQ(A(1, 0), 15);
}

TEST(Method, MulMatrix5) {
  S21Matrix A(3, 2), B(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  B(0, 0) = 3;
  B(1, 1) = 4;
  B(0, 2) = 5;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetCols(), 3);
}

// === Transpose ===
TEST(Method, Transpose1) {
  S21Matrix A(2, 3);
  A(0, 1) = 5;
  S21Matrix T = A.Transpose();
  EXPECT_EQ(T(1, 0), 5);
}

TEST(Method, Transpose2) {
  S21Matrix A(1, 1);
  A(0, 0) = 42;
  S21Matrix T = A.Transpose();
  EXPECT_EQ(T(0, 0), 42);
}

TEST(Method, Transpose3) {
  S21Matrix A(2, 2);
  A(0, 1) = 7;
  A(1, 0) = 3;
  S21Matrix T = A.Transpose();
  EXPECT_DOUBLE_EQ(T(1, 0), 7);
  EXPECT_DOUBLE_EQ(T(0, 1), 3);
}

TEST(Method, Transpose4) {
  S21Matrix A(3, 1);
  A(0, 0) = 1;
  A(1, 0) = 2;
  A(2, 0) = 3;
  S21Matrix T = A.Transpose();
  EXPECT_EQ(T.GetRows(), 1);
  EXPECT_EQ(T.GetCols(), 3);
}

TEST(Method, Transpose5) {
  S21Matrix A(3, 3);
  A(0, 1) = 9;
  S21Matrix T = A.Transpose();
  EXPECT_EQ(T(1, 0), 9);
}

// === Determinant ===
TEST(Method, Determinant1x1) {
  S21Matrix A(1, 1);
  A(0, 0) = 7;
  EXPECT_DOUBLE_EQ(A.Determinant(), 7);
}

TEST(Method, Determinant2) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  EXPECT_DOUBLE_EQ(A.Determinant(), -2);
}

TEST(Method, Determinant4) {
  S21Matrix A(3, 3);
  A(0, 0) = 6;
  A(0, 1) = 1;
  A(0, 2) = 1;
  A(1, 0) = 4;
  A(1, 1) = -2;
  A(1, 2) = 5;
  A(2, 0) = 2;
  A(2, 1) = 8;
  A(2, 2) = 7;
  EXPECT_DOUBLE_EQ(A.Determinant(), -306);
}

TEST(Method, Determinant5) {
  S21Matrix A(2, 2);
  A(0, 0) = 0;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  EXPECT_DOUBLE_EQ(A.Determinant(), -6);
}

// === CalcComplements ===
TEST(Method, CalcComplements1) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  S21Matrix C = A.CalcComplements();
  EXPECT_DOUBLE_EQ(C(0, 0), 4);
  EXPECT_DOUBLE_EQ(C(0, 1), -3);
  EXPECT_DOUBLE_EQ(C(1, 0), -2);
  EXPECT_DOUBLE_EQ(C(1, 1), 1);
}

TEST(Method, CalcComplements2) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(1, 1) = 1;
  A(2, 2) = 1;
  S21Matrix C = A.CalcComplements();
  EXPECT_DOUBLE_EQ(C(0, 0), 1);
}

TEST(Method, CalcComplements3) {
  S21Matrix A(1, 1);
  A(0, 0) = 7;
  S21Matrix C = A.CalcComplements();
  EXPECT_DOUBLE_EQ(C(0, 0), 1);
}

TEST(Method, CalcComplements4) {
  S21Matrix A(2, 2);
  A(0, 0) = 0;
  A(0, 1) = 1;
  A(1, 0) = 2;
  A(1, 1) = 3;
  S21Matrix C = A.CalcComplements();
  EXPECT_DOUBLE_EQ(C(0, 0), 3);
}

TEST(Method, CalcComplements5) {
  S21Matrix A(2, 2);
  A(0, 0) = -1;
  A(0, 1) = -2;
  A(1, 0) = 1;
  A(1, 1) = 2;
  S21Matrix C = A.CalcComplements();
  EXPECT_DOUBLE_EQ(C(0, 0), 2);
}

// === InverseMatrix ===
TEST(Method, InverseMatrix1x1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2;
  S21Matrix inv = A.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv(0, 0), 0.5);
}

TEST(Method, InverseMatrix2x2) {
  S21Matrix A(2, 2);
  A(0, 0) = 4;
  A(0, 1) = 7;
  A(1, 0) = 2;
  A(1, 1) = 6;
  S21Matrix inv = A.InverseMatrix();
  EXPECT_NEAR(inv(0, 0), 0.6, 1e-7);
  EXPECT_NEAR(inv(0, 1), -0.7, 1e-7);
  EXPECT_NEAR(inv(1, 0), -0.2, 1e-7);
  EXPECT_NEAR(inv(1, 1), 0.4, 1e-7);
}

TEST(Method, InverseMatrixIdentity) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(1, 1) = 1;
  S21Matrix inv = A.InverseMatrix();
  EXPECT_TRUE(inv == A);
}

TEST(Method, InverseMatrix4x4) {
  S21Matrix A(1, 1);
  A(0, 0) = 8;
  S21Matrix inv = A.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv(0, 0), 0.125);
}

TEST(Method, InverseMatrixNeg) {
  S21Matrix A(1, 1);
  A(0, 0) = -4;
  S21Matrix inv = A.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv(0, 0), -0.25);
}

TEST(Method, CalcComplements_1x1) {
  S21Matrix A(1, 1);
  A(0, 0) = 5.0;
  S21Matrix B = A.CalcComplements();
  EXPECT_EQ(B.GetRows(), 1);
  EXPECT_EQ(B.GetCols(), 1);
  EXPECT_DOUBLE_EQ(B(0, 0), 1.0);
}

TEST(Method, InverseMatrix_3x3) {
  S21Matrix A(3, 3);
  A(0, 0) = 3;
  A(0, 1) = 0;
  A(0, 2) = 2;
  A(1, 0) = 2;
  A(1, 1) = 0;
  A(1, 2) = -2;
  A(2, 0) = 0;
  A(2, 1) = 1;
  A(2, 2) = 1;

  S21Matrix inv = A.InverseMatrix();

  S21Matrix expected(3, 3);
  expected(0, 0) = 0.2;
  expected(0, 1) = 0.2;
  expected(0, 2) = 0.0;
  expected(1, 0) = -0.2;
  expected(1, 1) = 0.3;
  expected(1, 2) = 1.0;
  expected(2, 0) = 0.2;
  expected(2, 1) = -0.3;
  expected(2, 2) = 0.0;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) EXPECT_NEAR(inv(i, j), expected(i, j), 1e-7);
}

TEST(Method, InverseMatrix1x1_2) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;
  S21Matrix inv = A.InverseMatrix();
  EXPECT_DOUBLE_EQ(inv(0, 0), 0.5);
}

TEST(Method, InverseMatrix_3x3_2) {
  S21Matrix A(3, 3);
  A(0, 0) = 3;
  A(0, 1) = 0;
  A(0, 2) = 2;
  A(1, 0) = 2;
  A(1, 1) = 0;
  A(1, 2) = -2;
  A(2, 0) = 0;
  A(2, 1) = 1;
  A(2, 2) = 1;

  S21Matrix inv = A.InverseMatrix();

  S21Matrix expected(3, 3);
  expected(0, 0) = 0.2;
  expected(0, 1) = 0.2;
  expected(0, 2) = 0.0;
  expected(1, 0) = -0.2;
  expected(1, 1) = 0.3;
  expected(1, 2) = 1.0;
  expected(2, 0) = 0.2;
  expected(2, 1) = -0.3;
  expected(2, 2) = 0.0;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) EXPECT_NEAR(inv(i, j), expected(i, j), 1e-7);
}

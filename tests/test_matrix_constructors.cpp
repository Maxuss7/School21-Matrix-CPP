#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// === CONSTRUCTORS ===
TEST(Constructor, Default) {
  S21Matrix A;
  EXPECT_EQ(A.GetRows(), 1);
  EXPECT_EQ(A.GetCols(), 1);
  EXPECT_NEAR(A(0, 0), 0.0, 1e-7);
}

TEST(Constructor, Parametrized) {
  S21Matrix A(3, 4);
  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 4);
}

TEST(Constructor, Copy) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(1, 1) = 2.0;
  S21Matrix B = A;
  EXPECT_TRUE(B == A);
}

TEST(Constructor, Move) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  S21Matrix B = std::move(A);
  EXPECT_EQ(B(0, 0), 1.0);
}
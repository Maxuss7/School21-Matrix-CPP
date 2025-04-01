#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// Test suite: S21MatrixConstructorTest

TEST(S21MatrixConstructorTest, DefaultConstructorCreates1x1) {
  S21Matrix m;
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m.GetCols(), 1);
  EXPECT_DOUBLE_EQ(m(0, 0), 0.0);
}

TEST(S21MatrixConstructorTest, SizeConstructorCreatesCorrectSize) {
  S21Matrix m(3, 4);
  EXPECT_EQ(m.GetRows(), 3);
  EXPECT_EQ(m.GetCols(), 4);
}

TEST(S21MatrixConstructorTest, SizeConstructorThrowsOnInvalidSize) {
  EXPECT_THROW(S21Matrix(-1, 2), std::invalid_argument);  // rows <= 0
  EXPECT_THROW(S21Matrix(2, -1), std::invalid_argument);  // cols <= 0
  EXPECT_THROW(S21Matrix(0, 0), std::invalid_argument);   // оба <= 0
}

TEST(S21MatrixConstructorTest, CopyConstructorCreatesEqualMatrix) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(1, 1) = 2.0;
  S21Matrix m2(m1);
  EXPECT_TRUE(m1 == m2);
  m2(0, 0) = 9.0;
  EXPECT_FALSE(m1 == m2);
}

TEST(S21MatrixConstructorTest, MoveConstructorTransfersOwnership) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 42;
  S21Matrix m2(std::move(m1));
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 2);
  EXPECT_DOUBLE_EQ(m2(0, 0), 42);

  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
}

TEST(S21MatrixConstructorTest, CopyAssignmentCreatesEqualMatrix) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.5;
  S21Matrix m2;
  m2 = m1;
  EXPECT_TRUE(m1 == m2);
  m2(0, 0) = 7.0;
  EXPECT_FALSE(m1 == m2);
}

TEST(S21MatrixConstructorTest, MoveAssignmentTransfersOwnershipAndNullsSource) {
  S21Matrix m1(3, 3);
  m1(1, 1) = 8.8;
  S21Matrix m2;
  m2 = std::move(m1);
  EXPECT_EQ(m2.GetRows(), 3);
  EXPECT_EQ(m2.GetCols(), 3);
  EXPECT_DOUBLE_EQ(m2(1, 1), 8.8);
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
}

TEST(S21MatrixConstructorTest, DestructorCleansUpMemory) {
  S21Matrix* m = new S21Matrix(5, 5);
  (*m)(4, 4) = 99.0;
  delete m;
  SUCCEED();
}

TEST(S21MatrixConstructorTest, AllocateFreeMemoryWithZeroSize) {
  S21Matrix m1(1, 1);
  S21Matrix m2;
  m2 = std::move(m1);
  SUCCEED();
}

TEST(S21MatrixConstructorTest, InternalFreeOnEmptyMatrix) {
  S21Matrix m(1, 1);
  m = S21Matrix();  
                    /
  SUCCEED();
}

TEST(S21MatrixConstructorTest, ManuallyMoveToZeroMatrix) {
  S21Matrix m1(1, 1);
  S21Matrix m2(std::move(m1));  
  S21Matrix m3(std::move(m2));  
  SUCCEED();
}

TEST(S21MatrixConstructorTest, DestructorWithMultipleRowsCols) {
  S21Matrix* m = new S21Matrix(3, 3);
  (*m)(1, 1) = 123.456;
  delete m;
  SUCCEED();
}

TEST(S21MatrixConstructorTest, FreeMemoryDeletesMultipleRows) {
  S21Matrix m(3, 3);
  m = S21Matrix();
  SUCCEED();
}

TEST(S21MatrixEdgeTest, FreeMemoryWithMultipleRows) {
  S21Matrix m(10, 10);
  m = S21Matrix();
  SUCCEED();
}

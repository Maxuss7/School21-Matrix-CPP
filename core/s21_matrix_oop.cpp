// s21_matrix_oop.cpp
#include "s21_matrix_oop.h"

#include <cmath>
#include <cstring>

// ======== PRIVATE METHODS ========
void S21Matrix::AllocateMemory() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();  // zero-initialized
  }
}

void S21Matrix::FreeMemory() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  AllocateMemory();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::MoveMatrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = other.cols_ = 0;
}

S21Matrix S21Matrix::GetMinor(int row, int col) const {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0, mi = 0; i < rows_; ++i) {
    if (i == row) continue;
    for (int j = 0, mj = 0; j < cols_; ++j) {
      if (j == col) continue;
      minor.matrix_[mi][mj++] = matrix_[i][j];
    }
    ++mi;
  }
  return minor;
}

// ======== CONSTRUCTORS / DESTRUCTOR ========
S21Matrix::S21Matrix() : rows_(1), cols_(1) { AllocateMemory(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0)
    throw std::invalid_argument("Invalid matrix size");
  AllocateMemory();
}

S21Matrix::S21Matrix(const S21Matrix& other) { CopyMatrix(other); }

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  MoveMatrix(std::move(other));
}

S21Matrix::~S21Matrix() { FreeMemory(); }

// ======== ACCESSORS ========
int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) throw std::invalid_argument("Invalid row size");
  S21Matrix temp(rows, cols_);
  for (int i = 0; i < std::min(rows, rows_); ++i)
    for (int j = 0; j < cols_; ++j) temp.matrix_[i][j] = matrix_[i][j];
  *this = std::move(temp);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) throw std::invalid_argument("Invalid column size");
  S21Matrix temp(rows_, cols);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < std::min(cols, cols_); ++j)
      temp.matrix_[i][j] = matrix_[i][j];
  *this = std::move(temp);
}

// ======== MATRIX OPERATIONS ========
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) return false;
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrix dimensions must match");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrix dimensions must match");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(double num) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "Matrix dimensions incompatible for multiplication");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) result.matrix_[j][i] = matrix_[i][j];
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ == 1 && cols_ == 1) {
    S21Matrix result(1, 1);
    result(0, 0) = 1;
    return result;
  }

  if (rows_ != cols_)
    throw std::logic_error("Matrix must be square to calculate complements");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) {
      S21Matrix minor = GetMinor(i, j);
      double det = minor.Determinant();
      result.matrix_[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * det;
    }
  return result;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_)
    throw std::logic_error("Matrix must be square to compute determinant");
  if (rows_ == 1) return matrix_[0][0];
  if (rows_ == 2)
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  double result = 0.0;
  for (int j = 0; j < cols_; ++j) {
    S21Matrix minor = GetMinor(0, j);
    result += ((j % 2 == 0) ? 1 : -1) * matrix_[0][j] * minor.Determinant();
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ == 1) {
    if (std::fabs(matrix_[0][0]) < 1e-7)
      throw std::logic_error("Determinant is zero");
    S21Matrix result(1, 1);
    result(0, 0) = 1.0 / matrix_[0][0];
    return result;
  }

  double det = Determinant();
  if (std::fabs(det) < 1e-7) throw std::logic_error("Determinant is zero");
  S21Matrix complements = CalcComplements();
  S21Matrix transposed = complements.Transpose();
  transposed.MulNumber(1.0 / det);
  return transposed;
}

// ======== OPERATORS ========
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(double num) const {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    FreeMemory();
    CopyMatrix(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    FreeMemory();
    MoveMatrix(std::move(other));
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
    throw std::out_of_range("Index out of range");
  return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
    throw std::out_of_range("Index out of range");
  return matrix_[row][col];
}

S21Matrix operator*(double num, const S21Matrix& matrix) {
  return matrix * num;
}
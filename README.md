# 🧮 Matrix Library in C++

**Description**:  
An object-oriented matrix manipulation library written in C++.  
It provides essential matrix operations (addition, subtraction, multiplication), transformations (transposition), and advanced features such as determinant, complements, and inverse matrix calculation.

Designed with clean architecture, test-driven development, and full code coverage in mind.

---

### **Features**
- Object-oriented matrix class `S21Matrix`
- Constructors: default, parameterized, copy, move
- Basic operations: addition, subtraction, multiplication (matrix and scalar)
- Advanced math: transpose, determinant, algebraic complements, inverse matrix
- Operator overloads: `+`, `-`, `*`, `==`, `()`, `=`, `+=`, `-=`, `*=`
- Exception safety using `std::logic_error` and `std::invalid_argument`

---

### **Technologies Used**

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
- **GTest** for unit testing
- **gcov + gcovr** for code coverage
- **Makefile** for build automation
- **clang-format** for code style (Google style)

---

### **Usage**

#### **1. Clone the repository**
```bash
git clone https://github.com/Maxuss7/School21-Matrix-CPP.git
cd School21-Matrix-CPP
```

---

#### **2. Build the static library**
```bash
make
```
This compiles the source files into a static library `s21_matrix_oop.a`.

---

#### **3. Run tests**
```bash
make test
make run_test
```

To get an HTML code coverage report:
```bash
make coverage
```

This generates a report in `coverage_html/index.html` — open it in your browser:

---

#### **4. Include in your project**
To use the library, include the header:

```cpp
#include "s21_matrix_oop.h"
```

##### Example:

```cpp
#include "s21_matrix_oop.h"
#include <iostream>

int main() {
    S21Matrix A(2, 2), B(2, 2);
    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;

    S21Matrix C = A + B;

    std::cout << "A + B =\n";
    for (int i = 0; i < C.GetRows(); ++i) {
        for (int j = 0; j < C.GetCols(); ++j)
            std::cout << C(i, j) << " ";
        std::cout << "\n";
    }

    return 0;
}
```

Then compile your program:

```bash
g++ -std=c++20 -Iincludes main.cpp s21_matrix_oop.a -o main
./main
```

---

#### **5. Format the code**
To apply `clang-format` (Google style):
```bash
make clang
```

---

#### **6. Clean the project**
```bash
make clean
```
Removes object files, coverage reports, executables, etc.

---

### 🧪 Tests Structure

Tests are organized by functionality:

```
tests/
├── test_matrix_constructors.cpp
├── test_matrix_methods.cpp
├── test_matrix_operators.cpp
└── test_matrix_exceptions.cpp
```

All are executed via `make run_tests`.


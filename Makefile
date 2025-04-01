# sudo apt install libgtest-dev
# sudo apt install gcovr

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -Iincludes -fprofile-arcs -ftest-coverage
SRC_DIR = core
OBJ_DIR = obj
INCLUDES = includes
TEST_DIR = tests
LIB_NAME = s21_matrix_oop.a

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.test.o, $(TEST_SOURCES))

GTEST_FLAGS = `pkg-config --cflags --libs gtest gtest_main`

.PHONY: all clean test

all: clean $(LIB_NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIB_NAME): $(OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $^ -o $@ $(GTEST_FLAGS) --coverage
	./test

clang:
	clang-format -i $(SRC_DIR)/*.cpp $(INCLUDES)/*.h $(TEST_DIR)/*.cpp

coverage: test
	@mkdir -p coverage_html
	gcovr -r . --html --html-details -o coverage_html/index.html
	@echo "HTML coverage report: coverage_html/index.html"
	@which xdg-open > /dev/null && xdg-open coverage_html/index.html || echo "Open manually"

clean:
	rm -rf $(OBJ_DIR) *.a test coverage_html

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test
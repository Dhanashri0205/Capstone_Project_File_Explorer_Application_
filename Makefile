CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -I/usr/include
TARGET = FileExplorer
TEST_TARGET = test_file_explorer

# Object files
OBJS = src/main.o src/file_explorer.o src/Logger.o
TEST_OBJS = test/test_file_explorer.o src/file_explorer.o src/Logger.o

# Build the main target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Build the test target
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) -lCppUTest -lCppUTestExt

# Compile main.cpp
src/main.o: src/main.cpp include/FileExplorer.h include/Logger.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

# Compile file_explorer.cpp
src/file_explorer.o: src/file_explorer.cpp include/FileExplorer.h include/Logger.h
	$(CXX) $(CXXFLAGS) -c src/file_explorer.cpp -o src/file_explorer.o

# Compile Logger.cpp
src/Logger.o: src/Logger.cpp include/Logger.h
	$(CXX) $(CXXFLAGS) -c src/Logger.cpp -o src/Logger.o

# Compile test_file_explorer.cpp
test/test_file_explorer.o: test/test_file_explorer.cpp include/FileExplorer.h include/Logger.h
	$(CXX) $(CXXFLAGS) -c test/test_file_explorer.cpp -o test/test_file_explorer.o

# Clean the build directory
clean:
	rm -f $(TARGET) $(TEST_TARGET) src/.o test/.o

# Run the file explorer
run: $(TARGET)
	./$(TARGET)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# PHONY targets
.PHONY: clean run test

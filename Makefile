# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Source files and executable
SRC = src/main.cpp src/graph.cpp
OBJ = main.o graph.o
TARGET = social_network

# Compilation rule
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

main.o: src/main.cpp src/graph.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp

graph.o: src/graph.cpp src/graph.h
	$(CXX) $(CXXFLAGS) -c src/graph.cpp

# Clean rule to remove binaries
clean:
	rm -f $(TARGET) $(OBJ)

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2
TARGET := main
SOURCES := main.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SOURCES) LinkedList.hpp
   $(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
   ./$(TARGET)

clean:
   rm -f $(TARGET) $(TARGET).exe
CXX = clang++
CXXFLAGS = -Wall -std=c++17

TARGET = a
HEADERS = header.h
SOURCES = main.cpp functions.cpp
OBJ = main.o functions.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(TARGET)
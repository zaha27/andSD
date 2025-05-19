# Nume fișier executabil
TARGET = graf

# Compilator și opțiuni
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Surse
SRCS = parcurgeri/dfs.cpp \
       structuri/stiva/functions.cpp \
       structuri/coada/functions.cpp

# Fișiere obiect
OBJS = $(SRCS:.cpp=.o)

# Regulă principală
all: $(TARGET)

# Link executabil
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regula de compilare .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Curățare
clean:
	rm -f $(TARGET) $(OBJS)

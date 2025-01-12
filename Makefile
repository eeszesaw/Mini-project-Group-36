# Makefile for Contact Manager Project

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source files
SRC = main.cpp \
      AddContact.cpp \
      ContactManager.cpp \
      deleteContact.cpp \
      EditContact.cpp \
      ViewContact.cpp \
      SearchContact.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET = ContactManagerApp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

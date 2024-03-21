# EXEC = main

# all: $(EXEC)

# # Compile 

# main: main.cpp
# 	g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main

# run: $(EXEC)
# 	./$(EXEC)

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Source files
SRCS = main.cpp Food.cpp Snake.cpp

# Header files
HDRS = Food.hpp Snake.hpp Util.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = game

# Default target: build executable
all: $(EXEC)

# Compile source files to object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Target for running the executable
run: $(EXEC)
	./$(EXEC)

# Clean up intermediate files and executable
clean:
	rm -f $(EXEC) $(OBJS)

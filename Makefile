# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Paths
LIB_DIR = ./lib
SRC_DIR = ./src
BIN_DIR = ./bin

# SDL2 and other libraries
SDL2_LIB = -lSDL2 -lSDL2_image
# OTHER_LIB = -lOther

# Include paths
INCLUDE_DIRS = -I./include

# Source files and output
SRC = $(SRC_DIR)/main.cpp
OUT = $(BIN_DIR)/test

# Build target
all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p $(BIN_DIR)  # Create the bin directory if it doesn't exist
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $(OUT) $(SRC) -L$(LIB_DIR) $(SDL2_LIB)

# Clean up build files
clean:
	rm -f $(OUT)


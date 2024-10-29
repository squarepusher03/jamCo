# Compiler
CXX = g++-10

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -g 

# Paths
SRC_DIR = ./src
BIN_DIR = ./bin

# SDL2 and other libraries
SDL2_LIB = -lSDL2 -lSDL2_image
# OTHER_LIB = -lOther

# Include paths
INCLUDE_DIRS = -I./include
UI_INCLUDE = ./include/UI/
EVENT_INCLUDE = ./include/JamEvent.h

# Source files and output
SRC = $(SRC_DIR)/
UI_SRC = $(SRC_DIR)/UI/
OUT = $(BIN_DIR)/

OBJS = $(OUT)main.o $(OUT)Knob.o $(OUT)Element.o

# Build target
all: JamCo 

JamCo: $(OUT)main.o $(OUT)Knob.o
	@mkdir -p $(BIN_DIR)  # Create the bin directory if it doesn't exist
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $(OUT)JamCo $(OBJS) $(SDL2_LIB)

$(OUT)main.o: $(SRC)main.cpp $(OUT)Knob.o
	$(CXX) $(CXXFLAGS) -o $(OUT)main.o -c $(SRC)main.cpp

$(OUT)Knob.o: $(UI_INCLUDE)Knob.h $(UI_SRC)Knob.cpp $(OUT)Element.o $(EVENT_INCLUDE)
	$(CXX) $(CXXFLAGS) -o $(OUT)Knob.o -c $(UI_SRC)Knob.cpp

$(OUT)Element.o: $(UI_SRC)Element.cpp $(UI_INCLUDE)Element.h
	$(CXX) $(CXXFLAGS) -o $(OUT)Element.o -c $(UI_SRC)Element.cpp

# Clean up build files
clean:
	rm -f $(OUT)*


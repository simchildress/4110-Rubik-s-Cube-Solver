CXX = g++

SOURCES = main.cpp Solver.cpp Cube.cpp
OUTPUT = rubiks

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CXX) $(SOURCES) -o $(OUTPUT)
	
clean:
	rm -f $(OUTPUT)
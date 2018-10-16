CXX=g++
CXXFLAGS=-Wextra --std=c++17 -g
EXE=CS_Record_Label

all: $(EXE)

$(EXE): main.cpp $(wildcard *.hpp)
	$(CXX) -o $(EXE) main.cpp $(CXXFLAGS)

.PHONY: clean run

clean:
	rm -f $(EXE)

run: $(EXE)
	./$(EXE)

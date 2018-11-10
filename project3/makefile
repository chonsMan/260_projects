CXX=clang++
CXXFLAGS=-Wpedantic --std=c++17 -g
EXE=Websites

LIBS=steve hasher database
all: $(EXE)

$(EXE): main.cpp $(addsuffix .o, $(LIBS))
	$(CXX) main.cpp -o $(EXE) $(addsuffix .o, $(LIBS)) $(CXXFLAGS)

%.o: %.cpp %.hpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

.PHONY: clean run

clean:
	rm -f $(addsuffix .o, $(LIBS)) $(EXE)

run: $(EXE)
	./$(EXE)

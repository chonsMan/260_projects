CXX=clang++
CXXFLAGS=-Wpedantic --std=c++17 -g
EXE=hash_table

LIBS=steve hasher
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

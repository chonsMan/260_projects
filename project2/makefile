CXX=g++
CXXFLAGS=-Wextra --std=c++17 -g
EXE=restaurant

LIBS=stack queue group contact_info
all: $(EXE)

$(EXE): main.cpp $(addsuffix .o, $(LIBS))
	$(CXX) main.cpp -o $(EXE) $(addsuffix .o, $(LIBS)) $(CXXFLAGS)

%.o: %.cpp %.hpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

.PHONY: clean run

clean:
	rm -f $(LIBS) $(EXE)

run: $(EXE)
	$(EXE)

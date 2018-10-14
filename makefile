CXX=g++
CXXFLAGS=-Wextra --std=c++17 -g
EXE=CS_Record_Label

all: $(EXE)

$(EXE): main.cpp song.o artist.o label.o c_helpers.o interface.o
	$(CXX) -o $(EXE) main.cpp song.o artist.o label.o c_helpers.o interface.o $(CXXFLAGS)

song.o: song.cpp song.hpp
	$(CXX) -c -o song.o song.cpp $(CXXFLAGS)

artist.o: artist.cpp artist.hpp list.hpp
	$(CXX) -c -o artist.o artist.cpp $(CXXFLAGS)

label.o: label.cpp label.hpp list.hpp
	$(CXX) -c -o label.o label.cpp $(CXXFLAGS)

c_helpers.o: c_helpers.cpp c_helpers.hpp
	$(CXX) -c -o c_helpers.o c_helpers.cpp $(CXXFLAGS)

interface.o: interface.cpp interface.hpp
	$(CXX) -c -o interface.o interface.cpp $(CXXFLAGS)

.PHONY: clean run

clean:
	rm -f *.o $(EXE)

run: $(EXE)
	./$(EXE)

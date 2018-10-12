CXX=g++
CXXFLAGS=-Wextra --std=c++17
EXE=CS_Record_Label

all: $(EXE)

$(EXE): main.cpp song.o artist.o label.o c_helpers.o
	$(CXX) -o $(EXE) main.cpp song.o artist.o label.o c_helpers.o $(CXXFLAGS)

song.o: song.cpp song.hpp
	$(CXX) -c -o song.o song.cpp $(CXXFLAGS)

artist.o: artist.cpp artist.hpp
	$(CXX) -c -o artist.o artist.cpp $(CXXFLAGS)

label.o: label.cpp label.hpp
	$(CXX) -c -o label.o label.cpp $(CXXFLAGS)

c_helpers.o: c_helpers.cpp c_helpers.hpp
	$(CXX) -c -o c_helpers.o c_helpers.cpp $(CXXFLAGS)

.PHONY: clean run

clean:
	rm *.o $(EXE)

run: $(EXE)
	./$(EXE)

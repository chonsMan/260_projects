CXX=g++
CXXFLAGS=-Wextra --std=c++17
EXE=CS_Record_Label
 
all: $(EXE)
 
$(EXE): main.cpp list.o artist.o label.o
	$(CXX) -o $(EXE) main.cpp list.o artist.o $(CFLAGS)
 
list.o: list.cpp list.hpp
	$(CXX) -c -o list.o list.cpp $(CFLAGS)
 
artist.o: artist.cpp artist.hpp
	$(CXX) -c -o artist.o artist.cpp $(CFLAGS)
 
label.o: label.cpp label.hpp
	$(CXX) -c -o label.o label.cpp $(CFLAGS)
    
clean: .PHONY
	rm *.o $(EXE)
 
run: $(EXE)
	./$(EXE)

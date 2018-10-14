#include "c_helpers.hpp"
#include <cstring>

static const size_t READ_BUFFER_LEN = 512;



//**********************************************************************//
//Function: add_song(Song song)
//Inputs:   song
//Outputs:  void
//Purpose:  To add a new song to the list.
//**********************************************************************//
char * getline_allocated(std::istream & stream, char delimiter) {
    static char * const read_buffer = new char[READ_BUFFER_LEN]; // statics are initialized only once per program execution

    stream.getline(read_buffer, READ_BUFFER_LEN, delimiter);
    return strcpy_allocated(read_buffer);
}



//**********************************************************************//
//Function:
//  Inputs:   
// Outputs:  
// Purpose: Make a copy of the source on the heap
//**********************************************************************//
char * strcpy_allocated(char const * const source) { //don't alter string or local variable (source is a const pointer to const char)
    size_t length = std::strlen(source); 
    char * allocation = new char[length + 1]; 
    std::strcpy(allocation, source);
    return allocation;
}

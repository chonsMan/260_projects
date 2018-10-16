#ifndef C_HELPERS_HPP
#define C_HELPERS_HPP

#include <iostream>
#include <cstring>

char * strcpy_allocated(char const * const source) {
    size_t length = std::strlen(source);
    char * allocation = new char[length + 1];
    std::strcpy(allocation, source);
    return allocation;
}

char * getline_allocated(std::istream & stream, char delimiter = '\n') {
    static const size_t READ_BUFFER_LEN = 512;
    static char * const read_buffer = new char[READ_BUFFER_LEN];

    stream.getline(read_buffer, READ_BUFFER_LEN, delimiter);
    return strcpy_allocated(read_buffer);
}

#endif

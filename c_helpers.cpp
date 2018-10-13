#include "c_helpers.hpp"
#include <cstring>

static const size_t READ_BUFFER_LEN = 512;

char * getline_allocated(std::istream & stream, char delimiter) {
    static char * const read_buffer = new char[READ_BUFFER_LEN]; // statics are initialized only once per program execution

    stream.getline(read_buffer, READ_BUFFER_LEN, delimiter);
    return strcpy_allocated(read_buffer);
}

char * strcpy_allocated(char const * const source) {
    size_t length = std::strlen(source);
    char * allocation = new char[length + 1];
    std::strcpy(allocation, source);
    return allocation;
}

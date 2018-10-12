#include "c_helpers.hpp"
#include <cstring>

static const size_t READ_BUFFER_LEN = 512;

char * getline_allocated(std::istream & stream, char delimiter) {
    static char * const read_buffer = new char[READ_BUFFER_LEN]; // statics are initialized only once per program execution

    stream.getline(read_buffer, READ_BUFFER_LEN, delimiter);
    size_t read_bytes = std::strlen(read_buffer);
    char * allocation = new char[read_bytes + 1];
    std::strcpy(allocation, read_buffer);

    return allocation;
}

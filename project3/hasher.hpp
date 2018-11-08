#ifndef HASHER_HPP
#define HASHER_HPP
#include "steve.hpp"

struct Hasher {
    static uint32_t crc32(Steve const & input); 


private:
    static uint32_t const CRC32_TABLE[256];

};

#endif
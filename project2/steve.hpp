#ifndef STEVE_HPP
#define STEVE_HPP
#include<cstring>
#include<iostream>
#include "victor.hpp"


// The ":" States Steve is inheriting from Victor of char (Steve is a type of Victor)
struct Steve : public Victor<char>{
    Steve() = default;
    Steve(size_t reserved);
    Steve(char const * rhs);
    Steve(Steve const & rhs);
    Steve(Steve && rhs);
    // Parent destructors are called automatically
    ~Steve() = default;


    friend std::ostream & operator<<(std::ostream & lhs, Steve const & rhs);
};

#endif
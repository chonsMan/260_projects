#ifndef STEVE_HPP
#define STEVE_HPP
#include<cstring>
#include<iostream>
#include "victor.hpp"
#include <utility>


// The ":" States Steve is inheriting from Victor of char (Steve is a type of Victor)
struct Steve : public Victor<char>{
    Steve() = default;
    Steve(size_t reserved);
    Steve(char const * rhs);
    Steve(Steve const & rhs);
    Steve(Steve && rhs);
    // Parent destructors are called automatically
    ~Steve() = default;

    char const * c_str() const;
    void reserve(size_t cap);
    bool is_empty() const;
    void clear();

    Steve & operator=(char const * rhs);
    Steve & operator=(Steve const & rhs);
    Steve & operator=(Steve && rhs);
    bool operator==(char const * rhs) const;

    friend std::ostream & operator<<(std::ostream & lhs, Steve const & rhs);
    friend std::istream & getline(std::istream & lhs, Steve & rhs, char delim);
};

#endif
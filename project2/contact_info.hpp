#ifndef CONTACT_INFO_HPP
#define CONTACT_INFO_HPP
#include "steve.hpp"

struct ContactInfo{
    ContactInfo(Steve name, Steve email);
    ContactInfo(ContactInfo const & contact_info) = delete; // Copy constructor
    ContactInfo(ContactInfo && rhs); // Mutable (non-const) rvalue ref. Move constructor.
    ~ContactInfo() = default; //Everything is by value

private:
    Steve name, email;
};


#endif

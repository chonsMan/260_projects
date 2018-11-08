//File: steve.cpp
//Purpose: I made my own string class!

#include "steve.hpp"
#include <stdexcept>

Steve::Steve(size_t reserved) : Victor(reserved) {}



// To be used when Steve is made from string constant
Steve::Steve(char const * rhs) {
    size = strlen(rhs) + 1;
    capacity = size;
    reallocate(); // Create new array
    strcpy(vodka, rhs); // Copy string into the new array
}



Steve::Steve(Steve const & rhs) : Victor(rhs) {}



// Call move constructor for Victor. This will initialize the current object
// using the move constructor for the parent object.
Steve::Steve(Steve && rhs) : Victor(std::move(rhs)) {}




char const * Steve::c_str() const { return vodka; }

void Steve::reserve(size_t cap){
    if (cap < size){
        throw std::length_error ("Capacity is too small.");
    }

    resize(cap);
}




bool Steve::is_empty() const {
    return size == 0 || vodka[0] == '\0';
}


void Steve::clear() {
    if(vodka) delete[] vodka;
    vodka = nullptr;
    size = capacity = 0;
}

std::ostream & operator<<(std::ostream & lhs, Steve const & rhs){
    return lhs << rhs.vodka;
}


// Flush old stuff out and bring new in
Steve & Steve::operator=(char const * rhs){
    size_t length = strlen(rhs) + 1; //Get length of string
    size = capacity = length;
    delete[] reallocate(); // Delete old array
    strcpy(vodka, rhs); // Copy rhs into vodka
    return *this;
}


Steve & Steve::operator=(Steve const & rhs){
    size = rhs.size;
    capacity = rhs.capacity;
    delete[] reallocate();
    if (size > 0) strcpy(vodka, rhs.vodka);
    return *this;
}


Steve & Steve::operator=(Steve && rhs){
    delete[] vodka;
    vodka = rhs.vodka;
    size = rhs.size;
    capacity = rhs.capacity;
    rhs.vodka = nullptr;
    rhs.size = rhs.capacity = 0;
    return *this;
}



static size_t const READ_BUFF_LEN = 512;
std::istream & getline(
    std::istream & lhs, 
    Steve & rhs, 
    char delim
) {
    rhs.clear();
    rhs.reserve(READ_BUFF_LEN);
    char got;
    while ((got = lhs.get()) != delim) {
        rhs.push(got);
    }
    rhs.push('\0');
    return lhs;
}
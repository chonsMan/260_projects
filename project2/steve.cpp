#include "steve.hpp"
#include <utility>


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



char const * Steve::c_str(){ return vodka; }



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
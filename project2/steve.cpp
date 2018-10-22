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
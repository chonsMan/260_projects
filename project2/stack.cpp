//File: stack.cpp
//Purpose: Holds the contact information
#include "stack.hpp"
#include <stdexcept>

//Inputs: Reserved size
//Outputs: none
//Purpose: Constructor for a string 
Stack::Stack(size_t reserved) : Victor(reserved) {}


//Inputs: rhs argument
//Outputs: none
//Purpose: Constructs a copy
Stack::Stack(Stack const & rhs) : Victor(rhs) {}

//Move constructor
Stack::Stack(Stack && rhs) : Victor(rhs) {}


//Inputs: none
//Outputs: string 
ContactInfo & Stack::peek(){
    if(size == 0) throw std::length_error("Cannot peek and empty stack");
    return vodka[size-1];
}

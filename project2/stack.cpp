#include "stack.hpp"
#include <stdexcept>


Stack::Stack(size_t reserved) : Victor(reserved) {}


Stack::Stack(Stack const & rhs) : Victor(rhs) {}


Stack::Stack(Stack && rhs) : Victor(rhs) {}


ContactInfo & Stack::peek(){
    if(size == 0) throw std::length_error("Cannot peek and empty stack");
    return vodka[size-1];
}

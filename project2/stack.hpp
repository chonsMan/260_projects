#ifndef STACK_HPP
#define STACK_HPP
#include "victor.hpp"
#include "contact_info.hpp"

struct Stack : public Victor<ContactInfo> {
    Stack() = default;
    Stack(size_t reserved);
    Stack(Stack const & rhs);
    Stack(Stack && rhs);
    ~Stack() = default;
    
    ContactInfo & peek();
    
    ContactInfo & operator[](size_t) = delete; 


};


#endif 

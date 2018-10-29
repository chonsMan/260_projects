//File: contact_info.cpp
//Purpose: To hold list of people who want to be spammed
#include "contact_info.hpp"
#include <utility>

//Constructor
//Inputs: A name and an email
//Outputs: none
ContactInfo::ContactInfo(Steve name, Steve email) :
    name{std::move(name)}, email{std::move(email)}
{}


//Move Constructor
//Inputs: name and email (rhs)
//Outputs: None
//Used to move data (move semantics)
ContactInfo::ContactInfo(ContactInfo && rhs) :
    name{std::move(rhs.name)}, email{std::move(rhs.email)}
{}


//Operator=
//Purpose: Overload the '=' operator
ContactInfo & ContactInfo::operator=(ContactInfo const & rhs) {
    name = rhs.name;
    email = rhs.email;
    return *this;
}


//Move operator =
//Purpose: Overload the '=' operator for move semantics
ContactInfo & ContactInfo::operator=(ContactInfo && rhs) {
    name = std::move(rhs.name);
    email = std::move(rhs.email);
    return *this;
}


//Operator <<
//Purpose: Overload the << operator for output to user
std::ostream & operator<<(
    std::ostream & output,
    ContactInfo const & rhs
) {
    return output
    << rhs.name << ":  "
    << rhs.email << std::endl;
}


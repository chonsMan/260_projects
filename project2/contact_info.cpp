#include "contact_info.hpp"
#include <utility>

ContactInfo::ContactInfo(Steve name, Steve email) :
    name{std::move(name)}, email{std::move(email)}
{}

ContactInfo::ContactInfo(ContactInfo && rhs) :
    name{std::move(rhs.name)}, email{std::move(rhs.email)}
{}

ContactInfo & ContactInfo::operator=(ContactInfo const & rhs) {
    name = rhs.name;
    email = rhs.email;
    return *this;
}

ContactInfo & ContactInfo::operator=(ContactInfo && rhs) {
    name = std::move(rhs.name);
    email = std::move(rhs.email);
    return *this;
}



std::ostream & operator<<(
    std::ostream & output,
    ContactInfo const & rhs
) {
    return output 
    << rhs.name << '\n'
    << rhs.email << std::endl;
}


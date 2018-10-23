#include "contact_info.hpp"
#include <utility>

ContactInfo::ContactInfo(Steve name, Steve email) :
    name{std::move(name)}, email{std::move(email)}
{}

ContactInfo::ContactInfo(ContactInfo && rhs) :
    name{std::move(rhs.name)}, email{std::move(rhs.email)}
{}

ContactInfo & ContactInfo::operator=(ContactInfo const & rhs) {
    name = name;
    email = email;
}

ContactInfo & ContactInfo::operator=(ContactInfo && rhs) {
    name = std::move(name);
    email = std::move(email);
}

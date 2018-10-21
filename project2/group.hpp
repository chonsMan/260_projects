#ifndef GROUP_HPP
#define GROUP_HPP
#include "contact_info.hpp"

struct Group{
    Group(
        char const* name,
        int num_people,
        char const * special_seating,
        ContactInfo * contact_info // Manipulated w/ move contructor (not const)
    );
    Group(Group const & group) = delete; // Don't make a copy
    Group(Group && group); // Mutable move constructor
    ~Group();

private:
    char const * name;
    int num_people;
    char const * special_seating;
    ContactInfo const * contact_info;
};


#endif
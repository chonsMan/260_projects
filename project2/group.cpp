#include "group.hpp"


Group::Group(
    char const* name,
    int num_people,
    char const * special_seating,
    ContactInfo * contact_info
) :
    name{name}, 
    num_people{num_people},
    special_seating{special_seating},
    contact_info{contact_info}
{}


Group::Group(Group && rhs) : 
    name{rhs.name}, num_people{rhs.num_people}, special_seating{rhs.special_seating},
    contact_info{rhs.contact_info} 
{
    rhs.name = nullptr; // Snip on rhs
    rhs.num_people = 0;
    rhs.special_seating = nullptr;
    rhs.contact_info = nullptr;
}

Group::~Group(){
    if (name) delete[] name;
    if (special_seating) delete[] special_seating;
    if (contact_info) delete[] contact_info;
}
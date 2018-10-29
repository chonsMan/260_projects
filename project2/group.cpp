//File: group.cpp
//Purpose: To build a group that will be added to a waiting list


#include "group.hpp"
#include <utility>

//Constructor
Group::Group(
    Steve name,
    int num_people,
    Steve special_seating,
    std::optional<ContactInfo> contact_info
) :
    name{std::move(name)}, 
    num_people{num_people},
    special_seating{std::move(special_seating)},
    contact_info{std::move(contact_info)}
{}

//Move Constructor
Group::Group(Group && rhs) : 
    name{std::move(rhs.name)}, 
    num_people{rhs.num_people}, 
    special_seating{std::move(rhs.special_seating)},
    contact_info{std::move(rhs.contact_info)} 
{
    rhs.num_people = 0;
}


//Inputs: none
//Outputs: contact information
//Purpose: To return the contact information if a group wanted to be part of promo list
std::optional<ContactInfo> & Group::get_contact_info () {
    return contact_info;
}


//Operator overload for '<<' operator
std::ostream & operator<<(
    std::ostream & output,
    Group const & rhs 
) { 

output
    << rhs.name << '\n'
    << "Number of people: " << rhs.num_people << '\n';

if (!rhs.special_seating.is_empty())
    output << "Special seating: " << rhs.special_seating << '\n';

return output;
}

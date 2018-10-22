#include "group.hpp"
#include <utility>


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


Group::Group(Group && rhs) : 
    name{std::move(rhs.name)}, 
    num_people{rhs.num_people}, 
    special_seating{std::move(rhs.special_seating)},
    contact_info{std::move(rhs.contact_info)} 
{
    rhs.num_people = 0;
}

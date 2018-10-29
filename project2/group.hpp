#ifndef GROUP_HPP
#define GROUP_HPP
#include "contact_info.hpp"
#include "steve.hpp"
#include <optional>

struct Group{
    Group(
        Steve name,
        int num_people,
        Steve special_seating,
        std::optional<ContactInfo> contact_info // Manipulated w/ move contructor (not const)
    );
    Group(Group const & group) = delete; // Don't make a copy
    Group(Group && group); // Mutable move constructor
    // Group has value types and so nothing to delete
    ~Group() = default;

    std::optional<ContactInfo> & get_contact_info ();

    friend std::ostream & operator<<(
        std::ostream & output,
        Group const & rhs 
    );

private:
    Steve name;
    int num_people;
    Steve special_seating;
    std::optional<ContactInfo> contact_info;
};


#endif 
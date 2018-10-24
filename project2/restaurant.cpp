#include "restaurant.hpp"
#include "group.hpp"
#include <utility>
#include <fstream>


Restaurant::Restaurant(Steve file_name) : 
    file_name { std:: move(file_name) } {}



void Restaurant::add_group(
    Steve group_name,
    int members,
    Steve special_seating,
    std::optional<ContactInfo> spam
) {
    waiting_list.push ( 
        Group { 
            std::move(group_name), 
            members, 
            std::move(special_seating), 
            std::move(spam)
        }
    );
}



void Restaurant::seat_group() {
    Group group { waiting_list.pop() }; // Will call move constructor for this group bc functions return R values.
    if (group.get_contact_info().has_value()) {
        contacts.push(std::move(
            group.get_contact_info().value()
        ));
    }
}



void Restaurant::next_group(std::ostream & output) {
    output << waiting_list.peek();
}



void Restaurant::spam(std::ostream output) {
    ContactInfo info { contacts.pop() };
    output << info;
    std::ofstream outfile;
    outfile.open(file_name.c_str());
    outfile << info;
}   




std::ostream & operator<<(
    std::ostream & output,
    Restaurant const & rhs
) {
    return output << rhs.waiting_list;
}


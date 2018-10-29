//File: restaureant.cpp
//This is the top level of the data structure and handles all responsibilities for
//for the group and waiter. 

#include "restaurant.hpp"
#include "group.hpp"
#include <utility>
#include <fstream>


//Constructor
Restaurant::Restaurant(Steve file_name) : 
    file_name { std:: move(file_name) } {}


//Inputs: name, number of members, seating requirements, spam (option)
//Outputs: none
//Purpose: Add a group to the list
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


//Inputs: none
//Outputs: none
//Purpose: pop a group from the queue
void Restaurant::seat_group() {
    Group group { waiting_list.pop() }; // Will call move constructor for this group bc functions return R values.
    if (group.get_contact_info().has_value()) {
        contacts.push(std::move(
            group.get_contact_info().value()
        ));
    }
}


//Inputs: none
//Outputs: none
//Purpose: peek functionality
void Restaurant::next_group(std::ostream & output) {
    output << waiting_list.peek();
}


//Inputs: output
//Outputs: none
//Purpose: Add contact info to spam list
void Restaurant::spam(std::ostream & output) {
    ContactInfo info { contacts.pop() };
    output << info;
    std::ofstream outfile { file_name.c_str(), std::ios_base::app };
    outfile << info;
}   



//operator overload
std::ostream & operator<<(
    std::ostream & output,
    Restaurant const & rhs
) {
    return output << rhs.waiting_list;
}


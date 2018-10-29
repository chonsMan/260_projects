#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP
#include "queue.hpp"
#include "stack.hpp"
#include "steve.hpp"
#include <iostream>

struct Restaurant {
    Restaurant(Steve file_name);
    ~Restaurant() = default;

    // Add group
    void add_group(
        Steve group_name,
        int members,
        Steve special_seating,
        std::optional<ContactInfo> spam
    );
    // Seat group
    void seat_group();
    // See next group
    void next_group(std::ostream & output);
    // Spam a group
    void spam(std::ostream & output);

    friend std::ostream & operator<<(
        std::ostream & output,
        Restaurant const & rhs
    );

private:
    Queue waiting_list;
    Stack contacts;

    Steve file_name;
};

#endif 
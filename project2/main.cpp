//Name: Jesse Harris
//Class: CS260-0-44100
//Project2: Restaurant seating
//Purpose: Allow for restaurant to place a group on a waiting list. It also stores information 
//         about the guests if the choose to be a part of a promo list. 

#include "steve.hpp"
#include "restaurant.hpp"
#include "interface.hpp"
#include <iostream>


int main(){
    Restaurant restaurant { "Outfile" };
    while(
    interface_execute(std::cin, std::cout, restaurant)
    );
}

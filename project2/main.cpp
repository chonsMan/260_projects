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

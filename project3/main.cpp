#include "steve.hpp"
#include "database.hpp"
#include "topic.hpp"
#include <iostream>


int main() {
    Database database{};

    database.display_all(std::cout);
}
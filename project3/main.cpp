#include "steve.hpp"
#include "hash_table.hpp"
#include <iostream>


int main() {
    HashTable<Steve, int> hash;
    hash[Steve{"hello"}] = 56;
    hash[Steve{"world"}] = 100;

    std::cout << "56 is " << hash[Steve{"hello"}] << ", 100 is " << hash[Steve{"world"}] << std::endl;
}
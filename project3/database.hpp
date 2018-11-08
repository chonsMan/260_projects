#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "steve.hpp"
#include "victor.hpp"
#include "hash_table.hpp"
#include "topic.hpp"

struct Database {
    Database() = default;
    ~Database() = default;

    // Will take Steve and put it somewhere (don't pass
    // by reference. 
    void insert(Steve keyword, Topic topic);
    Victor<Steve> retrieve(Steve const & keyword);
    void edit(Steve const & keyword, Steve const & website, Steve review, Rating rating);

private:
    HashTable<Steve, Victor<Topic>> hash_table;
};



#endif
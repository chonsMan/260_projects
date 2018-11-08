#include "database.hpp"
#include <utility>
#include <stdexcept>


void Database::insert(Steve keyword, Topic topic) {
    hash_table[keyword].push(std::move(topic));
}

Victor<Steve> Database::retrieve(Steve const & keyword){
    Victor<Topic> & source = hash_table[keyword];
    Victor<Steve> websites { source.get_size() };
    for (int i = 0; i < source.get_size(); i++) {
        websites.push(source[i].website_address);
    }
    return websites;
}


void Database::edit(
    Steve const & keyword, 
    Steve const & website, 
    Steve review,
    Rating rating
) {
    Victor<Topic> & source = hash_table[keyword];
    Topic * topic = nullptr;
    for (int i = 0; i < source.get_size(); i++) {
        if (website == source[i].website_address) {
            topic = &source[i];
            break;
        }
    }

    if (topic == nullptr) throw std::runtime_error("Here is an empty string");

    topic->review = review;
    topic->rating = rating;
}
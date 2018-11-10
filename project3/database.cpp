#include "database.hpp"
#include "hash_table.hpp"
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



void print_topic_victor(std::ostream & output, Victor<Topic> & source) {
    for (int i = 0; i < source.get_size(); i++) {
        Topic const & topic = source[i];
        output << topic << '\n';
    }
}



void Database::display(std::ostream & output, Steve const & keyword) {
    print_topic_victor(output, hash_table[keyword]);
}



void Database::display_all(std::ostream & output) {
    // printer is funfaction
    auto printer = [&](Victor<Topic> & source){ print_topic_victor(output, source); };
    hash_table.for_each(printer);
}



void Database::remove() {
    auto predicate = [](Topic const & topic){
        return topic.rating != ONE;
    }; 

    auto culler = [=](Victor<Topic> & topics){ 
        topics.filter(predicate);
    };
    hash_table.for_each(culler);
}
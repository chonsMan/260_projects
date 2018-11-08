#ifndef TOPIC_HPP
#define TOPIC_HPP
#include "steve.hpp"

// An enum is the same as an int.; but possible values are restriced. 
// Create an int that can only be 1-5 (char is an enum with 256 states).
enum Rating {
    ONE, TWO, THREE, FOUR, FIVE
};

char const * display_rating(Rating rating) {
    switch (rating) {
        case   ONE: return "🌟";
        case   TWO: return "🌟🌟";
        case THREE: return "🌟🌟🌟";
        case  FOUR: return "🌟🌟🌟🌟";
        case  FIVE: return "🌟🌟🌟🌟🌟";
    }
}

struct Topic {
    Topic(Topic && rhs) : 
        topic_name { std::move(rhs.topic_name) },
        website_address { std::move(rhs.website_address) },
        summary { std::move(rhs.summary) },
        review { std::move(rhs.review) },
        rating { rhs.rating }
    {}

    Steve topic_name;
    Steve website_address;
    Steve summary;
    Steve review;
    Rating rating;

    Topic & operator=(Topic && rhs) {
        topic_name = std::move(rhs.topic_name);
        website_address = std::move(rhs.website_address);
        summary = std::move(rhs.summary);
        review = std::move(rhs.review);
        rating = rhs.rating;
        return *this;
    }
};

#endif
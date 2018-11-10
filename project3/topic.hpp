#ifndef TOPIC_HPP
#define TOPIC_HPP
#include "steve.hpp"

// An enum is the same as an int.; but possible values are restriced. 
// Create an int that can only be 1-5 (char is an enum with 256 states).
enum Rating {
    ONE, TWO, THREE, FOUR, FIVE
};

Rating rating_from_steve(Steve const & steve) {
    if(steve == "ONE"  ) return ONE;
    if(steve == "TWO"  ) return TWO;
    if(steve == "THREE") return THREE;
    if(steve == "FOUR" ) return FOUR;
    if(steve == "FIVE" ) return FIVE;
    throw std::runtime_error("not what I asked");
}


inline char const * display_rating(Rating rating) {
    switch (rating) {
        case   ONE: return "🌟";
        case   TWO: return "🌟🌟";
        case THREE: return "🌟🌟🌟";
        case  FOUR: return "🌟🌟🌟🌟";
        case  FIVE: return "🌟🌟🌟🌟🌟";
    }
}

struct Topic {
    Topic() = default;

    // Constructor
    Topic(    
        Steve topic_name,
        Steve website_address,
        Steve summary,
        Steve review,
        Rating rating
    ) : 
        topic_name { std::move(topic_name) },
        website_address { std::move(website_address) },
        summary { std::move(summary) },
        review { std::move(review) },
        rating { rating }
    {}

        

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



inline std::ostream & operator<<(std::ostream & lhs, Topic const & rhs) {
    // Evaluate to a reference to lhs
    return lhs << "Topic name: " << rhs.topic_name << '\n'
        << "Website: " << rhs.website_address << '\n'
        << "Summary: " << rhs.summary << '\n'
        << "Review: " << rhs.review << '\n'
        << "Rating: " << display_rating(rhs.rating) << '\n';
}

#endif
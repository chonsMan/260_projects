
//**********************************************************************//
//   File: interface.cpp
//Purpose: Allows top level interaction from user
//**********************************************************************//
#include "interface.hpp"


Steve prompt(
    std::ostream & output, 
    std::istream & input, 
    char const * message
) {
    output << message << std::endl;
    Steve response;
    getline(input, response, '\n');
    return response;
}

//Function: add_group
//Inputs:   Text from user
//Outputs:  Text for user
//Purpose:  Adds a group to the waiting list

void add_topic  (
    std::ostream & output, 
    std::istream & input, 
    Database & database
) {
    Steve keyword = prompt(output, input, "What keyword does this correspond to?");
    Steve name = prompt(output, input, "What is the name of the Topic?");
    Steve website_address = prompt(output, input, "What is the website?";
    Steve summary = prompt(output, input, "Please enter a summary");
    Steve review = prompt(output, input, "Please enter a review.";
    Steve rating = prompt(output, input, "Enter a rating (ONE, TWO, THREE, FOUR, FIVE).");

    database.insert(
        std::move(keyword), 
        Topic { 
            std::move(name),
            std::move(website_address),
            std::move(summary),
            std::move(review),
            rating_from_steve(rating)
        }
    );

}

void edit (
    std::ostream & output, 
    std::istream & input, 
    Database & database
) {
    Steve hash_key = prompt(output, input, "Please enter a topic.");
    Steve website = prompt(output, input, "Please enter a website."); 
    Steve review = prompt(output, input, "Please enter a review.");
    Steve rating = prompt(output, input, "Enter a rating (ONE, TWO, THREE, FOUR, FIVE).");

    database.edit(hash_key, website, std::move(review), rating_from_steve(rating));
}



void retrieve(
    std::ostream output, 
    std::istream input,
    Database & database
) {
    output << "Enter keyword." << std::endl;
    Steve hash_key;
    getline(input, hash_key, '\n');

    Victor<Steve> websites = database.retrieve(hash_key);

    for (size_t i{0}; i < websites.get_size(); i++) {
        output << websites[i] << '\n';
    }
    output.flush();
}


//Function: help
//Inputs:   A '?' from the user
//Outputs:  help list
//Purpose:  Display to the user what each option does
void help(std::ostream & output){
    output 
        << "a = add a topic\n" 
        << "e = edit\n"
        << "r = retrieve all websites for given topic\n"
        << "f = remove all 1 star ratings\n"
        << "d = display groups within given topic\n"
        << "s = display all groups\n"
        << "q = quit program" << std::endl;
}


//**********************************************************************//
//Function: interface_execute
//Inputs:   Text from user, restaurant
//Outputs:  Text for user
//Purpose:  Hols case statement for execution based on user input.
//**********************************************************************//
bool interface_execute(
    std::istream & input,
    std::ostream & output,
    Database & database
) {
    //Give user option for input. Devlop case statement for user option.
    output << "Hello! [a,e,r,f,d,s,q,? (for help)]?" << std::endl;
    Steve user_input;
    getline(input, user_input, '\n');
    switch (user_input[0]) {
        case 'a':
            add_group(output, input, restaurant);
            break;
        case 's':
            try {
                restaurant.seat_group();
            } catch(std::length_error & _) {
                output << "There are no more groups to seat." << std::endl;
            }
            break;
        case 'v':
            try {
                restaurant.next_group(output);
            } catch (std::length_error &_) {
                output << "There are no groups." << std::endl;
            }
            break;
        case 'f':
            restaurant.spam(output);
            break;
        case 'd':
            output << restaurant;
            break;
        case '?':
            help(output);
            break;
        case 'q': // quit
            return false;
        default:
            output << "Unrecognized command." << std::endl;;
    }

    input.clear();
    return true;
}




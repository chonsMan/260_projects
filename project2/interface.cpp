
//**********************************************************************//
//   File: interface.cpp
//Purpose: Allows top level interaction from user for adding an artist, 
//         adding a song, updating a song, removing a song, displaying
//         the restaurant, and removing songs.
//**********************************************************************//
#include "interface.hpp"


//**********************************************************************//
//Function: add_artist
//Inputs:   Text from user
//Outputs:  Text for user
//Purpose:  Allows for addition of artist, description, and top story.
//**********************************************************************//
void add_group  (
    std::ostream & output, 
    std::istream & input, 
    Restaurant & restaurant
) {
    output << "What is the name of the party?" << std::endl;;
    Steve name;
    getline(input, name, '\n');

    output << "How many are in the party?" << std::endl;
    int members;
    input >> members;
    input.ignore();

    output << "What special seating do you require? If none, press enter!" << std::endl;
    Steve special_seating;
    getline(input, special_seating, '\n');
    output << "Enter an email if you would like to be contacted for promos." << std::endl;
    Steve email;
    getline(input, email, '\n');

    std::optional<ContactInfo> spam {
        email.is_empty()
            ? std::nullopt
            : std::make_optional(ContactInfo { name, std::move(email) })
    };

    restaurant.add_group(
        std::move(name), 
        members, 
        std::move(special_seating),
        std::move(spam)
    );
}


//**********************************************************************//
//Function: help
//Inputs:   A '?' from the user
//Outputs:  help list
//Purpose:  Display to the user what each option does
//**********************************************************************//
void help(std::ostream & output){
    output 
        << "a = add a group\n" 
        << "s = seat a group\n"
        << "v = view next group\n"
        << "f = spam groups\n"
        << "d = display groups\n"
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
    Restaurant & restaurant
) {
    //Give user option for input. Devlop case statement for user option.
    output << "Hello! [a,s,v,f,d,q,? (for help)]?" << std::endl;
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




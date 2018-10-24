
//**********************************************************************//
//   File: interface.cpp
//Purpose: Allows top level interaction from user for adding an artist, 
//         adding a song, updating a song, removing a song, displaying
//         the label, and removing songs.
//**********************************************************************//
#include "interface.hpp"
#include "c_helpers.hpp"


//**********************************************************************//
//Function: add_artist
//Inputs:   Text from user
//Outputs:  Text for user
//Purpose:  Allows for addition of artist, description, and top story.
//**********************************************************************//
void add_artist  (std::ostream & output, std::istream & input, Label & label){
    output << "What is the name of the artist?" << std::endl;;
    char * artist = getline_allocated(input);
    output << "What is the description" << std::endl;;
    char * description = getline_allocated(input);
    output << "What is the top story?" << std::endl;;
    char * top_story = getline_allocated(input);

    try {
        label.add_artist(artist, description, top_story); //catch error if aritist does not exist
    } catch (std::runtime_error & err) {
        output << err.what() << '\n';
    }

    delete[] artist; //delete entire artist; not just what the pointer points to 
    delete[] description;
    delete[] top_story;
}


//**********************************************************************//
//Function: add_song
//Inputs:   Text from user
//Outputs:  Text from user
//Purpose:  To add a new song to the list.
//**********************************************************************//
void add_song(std::ostream & output, std::istream & input, Label & label){
    output << "Which artist?" << std::endl;;
    char * artist = getline_allocated(input);
    output << "What song would you like to add?" << std::endl;;
    char * song = getline_allocated(input);
    output << "How long is the song?" << std::endl;;
    float length;
    input >> length;
    input.ignore();
    output << "How many views?" << std::endl;;
    int views;
    input >> views;
    input.ignore();
    output << "How many likes?" << std::endl;
    int likes;
    input >> likes;
    input.ignore();
  
    try {
        label.add_song(artist, song, length, views, likes); //catch error if artist does not exist
    } catch (std::runtime_error & err) {
        output << err.what() << std::endl;
    }

    delete[] song; 
    delete[] artist; //delete entire artist; not just what the pointer points to 

}


//**********************************************************************//
//Function: add_song(Song song)
//Inputs:   Text from user
//Outputs:  Text for user
//Purpose:  Update song in list
//**********************************************************************//
void update_song (std::ostream & output, std::istream & input, Label & label){
    output << "Which artist?" << std::endl;;
    char * artist = getline_allocated(input);
    output << "Which song?" << std::endl;;
    char * song = getline_allocated(input);
    output << "How many views?" << std::endl;;
    int views;
    input >> views;
    input.ignore();
    output << "How many likes?" << std::endl;
    int likes;
    input >> likes;
    input.ignore();
  
    try {
        label.update_song(artist, song, views, likes); //catch error if aritist or song does not exist.
    } catch (std::runtime_error & err) {
        output << err.what() << std::endl;
    }

    delete[] song; 
    delete[] artist; //delete entire artist; not just what the pointer points to 
}


//**********************************************************************//
//Function: remove_songs
//Inputs:   Text from user
//Outputs:  Text for user
//Purpose:  To add a new song to the list.
//**********************************************************************//
void remove_songs(std::ostream & output, std::istream & input, Label & label){
    output << "What are the minimum number of views?" << std::endl;
    int min;
    input >> min;
    input.ignore();
    label.cull(min); 
}


//**********************************************************************//
//Function: display
//Inputs:   Text from user
//Outputs:  Text for user
//Purpose:  Display the list of the record label
//**********************************************************************//
void display(std::ostream & output, Label const & label) {
    output << label << std::endl;
}



//**********************************************************************//
//Function: help
//Inputs:   A '?' from the user
//Outputs:  help list
//Purpose:  Display to the user what each option does
//**********************************************************************//
void help(std::ostream & output){
    output 
        << "a = add artist\n" 
        << "u = update song\n"
        << "s = add song\n"
        << "r = remove songs\n"
        << "d = display list\n"
        << "q = quit program" << std::endl;
}


//**********************************************************************//
//Function: interface_execute
//Inputs:   Text from user, label
//Outputs:  Text for user
//Purpose:  Hols case statement for execution based on user input.
//**********************************************************************//
bool interface_execute(
    std::istream & input,
    std::ostream & output,
    Label & label
) {
    //Give user option for input. Devlop case statement for user option.
    output << "Hello! [a,u,s,r,d,q,?]?" << std::endl;
    char * user_input = getline_allocated(input);
    switch (user_input[0]) {
        case 'a':
            add_artist(output, input, label);
            break;
        case 'u':
            update_song(output, input, label);
            break;
        case 's':
            add_song(output, input, label);
            break;
        case 'r':
            remove_songs(output, input, label);
            break;
        case 'd':
            display(output, label);
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




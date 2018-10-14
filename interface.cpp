#include "interface.hpp"
#include "c_helpers.hpp"

void add_artist  (std::ostream & output, std::istream & input, Label & label){
    output << "What is the name of the artist?" << std::endl;;
    char * artist = getline_allocated(input);
    output << "What is the description" << std::endl;;
    char * description = getline_allocated(input);
    output << "What is the top story?" << std::endl;;
    char * top_story = getline_allocated(input);

    try {
        label.add_artist(artist, description, top_story);
    } catch (std::runtime_error & err) {
        output << err.what() << '\n';
    }

    delete[] artist; //delete entire artist; not just what the pointer points to 
    delete[] description;
    delete[] top_story;
}


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
        label.add_song(artist, song, length, views, likes);
    } catch (std::runtime_error & err) {
        output << err.what() << std::endl;
    }

    delete[] song; 
    delete[] artist; //delete entire artist; not just what the pointer points to 

}
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
        label.update_song(artist, song, views, likes);
    } catch (std::runtime_error & err) {
        output << err.what() << std::endl;
    }

    delete[] song; 
    delete[] artist; //delete entire artist; not just what the pointer points to 
}
void remove_songs(std::ostream & output, std::istream & input, Label & label){
    output << "What are the minimum number of views?" << std::endl;
    int min;
    input >> min;
    input.ignore();
    label.cull(min); 
}
void display(std::ostream & output, Label const & label) {
    output << label << std::endl;
}


void help(std::ostream & output){
    output 
        << "a = add artist\n" 
        << "u = update song\n"
        << "s = add song\n"
        << "r = remove songs\n"
        << "d = display list\n"
        << "q = quit program" << std::endl;
}

bool interface_execute(
    std::istream & input,
    std::ostream & output,
    Label & label
) {

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




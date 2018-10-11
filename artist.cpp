#include "artist.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <exception>


void Artist::cull(int minimum_views){
    song_list.filter(
        [=](Song const & song){//pass by value
            return song.views >= minimum_views;//
        }
    );
}


void Artist::update_song(char const* song_title, int likes, int views){
    Song song; 
    try {
        song = song_list.remove(Song::dummy(song_title));
    } catch (std::runtime_error& _err){
        throw std::runtime_error("Song not found");
    }
    
    song.likes = likes;
    song.views = views;
    song_list.insert_sort(song);
}



//**********************************************************************//
//Function: add_song(xxx)
//Inputs:   song name, length, likes, views.
//Outputs:  True if updated; false if not.
//Purpose:  To add a new song to the list.
//**********************************************************************//
void Artist::add_song(
        char const * song_title,
        float length,
        int likes,
        int views
) {
    Song song = Song{song_title, length, views, likes};
    if (song_list.find(song)) throw std::runtime_error("Song not found");
    song_list.insert_sort(song); 
}



//**********************************************************************//
//Function: 
//Inputs:   
//Outputs:  
//Purpose:  Song factory.
//**********************************************************************//
Song Song::dummy(char const* title){
    return Song{title, 0, 0, 0};
}



//**********************************************************************//
//Function: 
//Inputs:   
//Outputs:  
//Purpose:  Song factory.
//**********************************************************************//
Song Song::parse(std::istream& stream){
    Song song;

    stream.getline(Song::buffer, BUFF_LEN,';');
    size_t read_bytes = strlen(Song::buffer);//get num bytes read; so we know how much to allocate and copy
    char * title = new char[read_bytes]; //tie it to a mutable variable (non-const char pointer). Heap allocation.
    strcpy(title, Song::buffer); //copy from read buffer into title buffer
    song.title = title; //tie the title buffer to the song

    stream >> song.length;
    stream.get();
    stream >> song.views;
    stream.get();
    stream >> song.likes;
    stream.get();

    return song;
}



//**********************************************************************//
//Function: 
//Inputs:   
//Outputs:  
//Purpose:  Song factory. Static buffer to call parse over and over and 
//          if there were a new buffer for each one it woul be allocated
//          and destroyes, ad infinitum.
//**********************************************************************//
Artist Artist::parse(std::istream& stream){
    size_t read_bytes;
    Artist artist;

    stream.getline(Artist::buffer, BUFF_LEN,';');
    read_bytes = strlen(Artist::buffer);//get num bytes read; so we know how much to allocate and copy
    char * name = new char[read_bytes]; //tie it to a mutable variable (non-const char pointer). Heap allocation.
    strcpy(name, Artist::buffer); //copy from read buffer into title buffer
    artist.name = name; //tie the title buffer to the song

    stream.getline(Artist::buffer, BUFF_LEN,';');
    read_bytes = strlen(Artist::buffer);//get num bytes read; so we know how much to allocate and copy
    char * description = new char[read_bytes]; //tie it to a mutable variable (non-const char pointer). Heap allocation.
    strcpy(description, Artist::buffer); //copy from read buffer into title buffer
    artist.description = description; //tie the title buffer to the song

    stream.getline(Artist::buffer, BUFF_LEN,'\n');
    read_bytes = strlen(Artist::buffer);//get num bytes read; so we know how much to allocate and copy
    char * top_story = new char[read_bytes]; //tie it to a mutable variable (non-const char pointer). Heap allocation.
    strcpy(top_story, Artist::buffer); //copy from read buffer into title buffer
    artist.top_story = top_story; //tie the title buffer to the song

    return artist;
}



//**********************************************************************//
//Function: 
//Inputs:   
//Outputs:  
//Purpose:  Song factory.
//**********************************************************************//
bool Song::operator == (Song const & rhs) const {
    return std::strcmp(title, rhs.title) == 0;//return distance between different chars; zero if equal
}



//**********************************************************************//
//Function: 
//Inputs:   
//Outputs:  
//Purpose:  Song factory.
//**********************************************************************//
bool Artist::operator == (Artist const & rhs) const {
    return std::strcmp(name, rhs.name) == 0;//return distance between different chars; zero if equal
} 


//**********************************************************************//
//Function: 
//Inputs:   
//Outputs:  
//Purpose:  Song factory.
//**********************************************************************//
std::ostream& operator<<(std::ostream & lhs, Artist & rhs) {
    lhs
        << rhs.name << ';'
        << rhs.description << ';'
        << rhs.top_story << '\n';
    return lhs;
}

char * Song::buffer = new char[Song::BUFF_LEN];//declaration of the value
char * Artist::buffer = new char[Artist::BUFF_LEN]; //static function needs to get a value, only will happen once b/c in .cpp

//**********************************************************************//
//   File: artist.cpp
//Purpose: Contains functions that add an artist or a song; update an
//         existing song; or deletes a song based on a minumum number
//         of views.
//**********************************************************************//
#include "artist.hpp"
#include "c_helpers.hpp"
#include <iostream>
#include <cstring>
#include <exception>



//**********************************************************************//
//Function: constructor (basic)
//Inputs:   name, description, top_story
//Outputs:  void
//Purpose:  Allocate a new artist. This is allocated on the heap, so that
//          the artist can do with it what it wants. 
//**********************************************************************//
Artist::Artist(char const* name, char const * description, char const * top_story) :
    name(strcpy_allocated(name)),
    description(strcpy_allocated(description)),
    top_story(strcpy_allocated(top_story))
{};



//**********************************************************************//
//Function: constructor (dummy)
//Inputs:   name
//Outputs:  void
//Purpose:  Dummy artist used to search the list.
//**********************************************************************//
Artist::Artist(char const * name) : name(strcpy_allocated(name)) {}



//**********************************************************************//
//Function: destructor
//Inputs:   song
//Outputs:  void
//Purpose:  Destruct the list
//**********************************************************************//
Artist::~Artist() {
    if (name) delete name;
    if (description) delete description;
    if (top_story) delete top_story;
    name = description = top_story = nullptr;
}



//**********************************************************************//
//Function: cull
//Inputs:   minimun number of views
//Outputs:  void
//Purpose:  Deletes songs that less than input number of views.
//**********************************************************************//
void Artist::cull(int minimum_views) {
    song_list.filter(
        [=](Song const & song){ // [=] means pass captures by value
            return song.get_views() >= minimum_views;
        }
    );
}



//**********************************************************************//
//Function: update_song
//  Inputs: title, likes, views
// Outputs: void
// Purpose: Finds the artists that needs to be updated. Calls update
//          functionality.
//**********************************************************************//
void Artist::update_song(char const * song_title, int likes, int views) {
    Song * original;

    try {
        original = song_list.remove(Song(song_title));
    } catch (std::runtime_error& _err){
        throw std::runtime_error("Song not found");
    }

    song_list.insert_sort(
        new Song {
            original->get_title(),
            original->get_length(),
            likes,
            views
        }
    );

    delete original;
}



//**********************************************************************//
//Function: add_song(Song song)
//Inputs:   song
//Outputs:  Runtime error if song exists.
//Purpose:  To add a new song to the list.
//**********************************************************************//
void Artist::add_song(Song * song) {
    if (song_list.find(*song)) throw std::runtime_error("Song already exists for this artist");
    song_list.insert_sort(song);
}



//**********************************************************************//
//Function: comparator operator overload
//  Inputs: Right hand side of equivalency
// Outputs: 0 if names are the same
// Purpose: Compare input artist  to the artist list to find an artist.
//**********************************************************************//
bool Artist::operator==(Artist const & rhs) const {
    //return distance between different chars; zero if equal
    return std::strcmp(name, rhs.name) == 0;
}



//**********************************************************************//
//Function: ostream & operator
//  Inputs: stream and artist
//Outputs:  none
//Purpose:  Used tyo stream artist information out to the user.
//**********************************************************************//
std::ostream & operator<<(std::ostream & stream, Artist const & artist) {
    return stream
        << '!'
        << artist.name << ';'
        << artist.description << ';'
        << artist.top_story << '\n'
        << artist.song_list;
}



//**********************************************************************//
//Function: istream operator
//  Inputs: stram and artist
// Outputs: none
// Purpose: Used to read data in from a file.
//**********************************************************************//
std::istream & operator>>(std::istream & stream, Artist & artist) {
    stream.get(); // Consume '!'
    artist.name = getline_allocated(stream, ';'); //stream name and delimit the semi-colon
    artist.description = getline_allocated(stream, ';');
    artist.top_story = getline_allocated(stream, '\n');

    while (stream.peek() != '!' && stream.peek() != -1) {//while not at new artist and not at end
        Song * song = new Song;//TODO: 
        stream >> *song;
        artist.add_song(song);
    }

    return stream;
}

#include "artist.hpp"
#include "c_helpers.hpp"
#include <iostream>
#include <cstring>
#include <exception>

Artist::Artist(char const* name, char const * description, char const * top_story) :
    name(strcpy_allocated(name)),
    description(strcpy_allocated(description)),
    top_story(strcpy_allocated(top_story))
{};

Artist::Artist(char const * name) : name(strcpy_allocated(name)) {}

Artist::~Artist() {
    if (name) delete name;
    if (description) delete description;
    if (top_story) delete top_story;
    name = description = top_story = nullptr;
}

void Artist::cull(int minimum_views) {
    song_list.filter(
        // [=] means pass captures by value
        [=](Song const & song){
            return song.get_views() >= minimum_views;
        }
    );
}

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
//Outputs:  void
//Purpose:  To add a new song to the list.
//**********************************************************************//
void Artist::add_song(Song * song) {
    if (song_list.find(*song)) throw std::runtime_error("Song already exists for this artist");
    song_list.insert_sort(song);
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:  Song factory.
//**********************************************************************//
bool Artist::operator==(Artist const & rhs) const {
    //return distance between different chars; zero if equal
    return std::strcmp(name, rhs.name) == 0;
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:  Song factory.
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
//Function:
//Inputs:
//Outputs:
//Purpose:
//**********************************************************************//
std::istream & operator>>(std::istream & stream, Artist & artist) {
    stream.get(); // Consume '!'
    artist.name = getline_allocated(stream, ';');
    artist.description = getline_allocated(stream, ';');
    artist.top_story = getline_allocated(stream, '\n');

    while (stream.peek() != '!' && stream.peek() != -1) {
        Song * song = new Song;
        stream >> *song;
        artist.add_song(song);
    }

    return stream;
}

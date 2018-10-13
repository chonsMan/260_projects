#include "artist.hpp"
#include "c_helpers.hpp"
#include <iostream>
#include <cstring>
#include <exception>

Artist::Artist(char const* name, char const * description, char const * top_story)
    : name(name), description(description), top_story(top_story) {};

Artist Artist::dummy(char const * name) {
    return Artist { name, nullptr, nullptr };
}

void Artist::cull(int minimum_views) {
    song_list.filter(
        // [=] means pass captures by value
        [=](Song const & song){
            return song.get_views() >= minimum_views;
        }
    );
}

Artist::~Artist() {
    delete name;
    delete description;
    delete top_story;
}

void Artist::update_song(char const* song_title, int likes, int views) {
    Song original;

    try {
        original = song_list.remove(Song::dummy(song_title));
    } catch (std::runtime_error& _err){
        throw std::runtime_error("Song not found");
    }

    song_list.insert_sort(
        Song {
            original.get_title(),
            original.get_length(),
            likes,
            views
        }
    );
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
    Song song = Song { song_title, length, views, likes };
    if (song_list.find(song)) throw std::runtime_error("Song not found");
    song_list.insert_sort(song);
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:  Song factory.
//**********************************************************************//
Artist Artist::parse(std::istream & stream){
    size_t read_bytes;
    Artist artist;

    artist.name = getline_allocated(stream, ';');
    artist.description = getline_allocated(stream, ';');
    artist.top_story = getline_allocated(stream, '\n');

    return artist;
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
std::ostream & operator<<(std::ostream & lhs, Artist const & rhs) {
    return lhs
        << '!'
        << rhs.name << ';'
        << rhs.description << ';'
        << rhs.top_story << '\n'
        << rhs.song_list;
}

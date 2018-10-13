//**********************************************************************//
//File:    artist.hpp
//Purpose: This file houses the artist structure, which is the second
//		   layer that interacts with the song list. It has two
//         constructors; one of which is used as a dummy to check if any
//         artist already exists. It also has a cull function that is
//         called by the top layer (label.cpp) and used to cull a song.
//         It also houses functions to add and updata song, both of which
//         are called from the top layer. It has the name, top story, and
//         description private member variables and a private list of
//         songs  of type Song.
//**********************************************************************//
#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "list.hpp"
#include "song.hpp"

struct Artist {
    Artist(char const* name, char const * description, char const * top_story); //basic constructor
    static Artist dummy(char const * name); //constructor for checking if artist already exists
    static Artist parse(std::istream & stream);
    ~Artist();

    void cull(int minimum_views);
    void add_song(
        char const * song_title,
        float length,
        int likes,
        int views
    );
    void update_song(
        char const* song_title,
        int likes,
        int views
    );

    bool operator==(Artist const & rhs) const;
    friend std::ostream & operator<<(std::ostream & lhs, Artist const & rhs);

private:
    Artist() = default; //default constructor.

    char const * name, * top_story, * description;
    List<Song> song_list;
};

#endif

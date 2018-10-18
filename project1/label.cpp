//**********************************************************************//
//File: label.cpp
//Purpose: Contains functions that add an artist or a song; update an
//         existing song; or deletes a song based on a minumum number
//         of views.
//**********************************************************************//
#include <exception>
#include <iostream>

#include "label.hpp"
#include "song.hpp"
#include "c_helpers.hpp"

//**********************************************************************//
//Function: add_artist(xxx)
//Inputs:   Artist
//Outputs:  void
//Purpose:  This functions simply adds an artist to a list of other
//          artist_list.
//**********************************************************************//
void Label::add_artist(Artist * artist) {
    if(artist_list.find(*artist)) throw std::runtime_error("Artist already exists");
    artist_list.push_front(artist);
}



//**********************************************************************//
//Function: add_artist(xxx)
//Inputs:   Artist's name, description, and top story
//Outputs:  void
//Purpose:  This functions simply adds an artist to a list of other
//          artist_list.
//**********************************************************************//
void Label::add_artist(
    char const * artist_name,
    char const * description,
    char const * top_story
) {
    add_artist(new Artist { artist_name, description, top_story });//call private constructor
}



//**********************************************************************//
//Function: update_song()
//Inputs:   Artist's name, song name, likes, views
//Outputs:  True if updated; false if not.
//Purpose:  This function updates the number of views and likes.
//**********************************************************************//
void Label::update_song(
    char const * artist_name,
    char const * song_title,
    int likes,
    int views
) {
    Artist * const artist = artist_list.find(Artist(artist_name));
    if (!artist) throw std::runtime_error("Artist not found");
    artist->update_song(song_title, likes, views);//return success
}



//**********************************************************************//
//Function: cull(int minimum_views)
//Inputs:   An intiger value of minimum views
//Outputs:  void
//Purpose:  To remove a song that does not exceed the view threshold.
//**********************************************************************//
void Label::cull(int minimum_views){
    artist_list.for_each(
        // [=] means pass captures by value
        [=](Artist & artist){
            artist.cull(minimum_views);
        }
    );
}



//**********************************************************************//
//Function: add_song(xxx)
//Inputs:   Artist's name, song name, length, likes, views.
//Outputs:  True if updated; false if not.
//Purpose:  To add a new song to the list.
//**********************************************************************//
void Label::add_song(
        char const * artist_name,
        char const * song_title,
        float length,
        int likes,
        int views
) {
    Artist * const artist = artist_list.find(Artist(artist_name));
    if (!artist) throw std::runtime_error("Artist not found");
    artist->add_song(new Song { song_title, length, views, likes });
}



//**********************************************************************//
//Function: add_song(Song song)
//Inputs:   song
//Outputs:  void
//Purpose:  To add a new song to the list.
//**********************************************************************//
std::ostream & operator<<(std::ostream & stream, Label const & label) {
    return stream << label.artist_list;
}



//**********************************************************************//
//Function: add_song(Song song)
//Inputs:   song
//Outputs:  void
//Purpose:  To add a new song to the list.
//**********************************************************************//
std::istream & operator>>(std::istream & stream, Label & label) {
    while (stream.peek() != -1) { //peek looks ar next char w/o removing from stream. -1 is at end.
        Artist * artist = new Artist;//call default constructor
        stream >> *artist; //read an artist from stream
        label.add_artist(artist);
    }

    return stream;
}

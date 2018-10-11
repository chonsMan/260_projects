//**********************************************************************//
//File: label.cpp
//Purpose: Contains functions that add an artist or a song; update an
//         existing song; or deletes a song based on a minumum number 
//         of views.
//**********************************************************************//
#include "label.hpp"
#include <exception>



//**********************************************************************//
//Function: add_artist(xxx)
//Inputs:   Artist's name, description, and top story
//Outputs:  true if artist was added; false if existing
//Purpose:  This functions simply adds an artist to a list of other
//          artist_list.
//**********************************************************************//
void Label::add_artist(
    char const * artist_name, 
    char const * description, 
    char const * top_story
) {
    Artist artist = Artist {artist_name, description, top_story};
    if(artist_list.find(artist)) throw std::runtime_error("Artist already exists");
    artist_list.push_front(artist);
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
    Artist* artist = artist_list.find(Artist{ artist_name, nullptr, nullptr });
    if (artist == nullptr) throw std::runtime_error("Artist not found"); 
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
        [=](Artist& artist){//pass by value
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
    Artist* artist = artist_list.find(Artist{ artist_name, nullptr, nullptr });
    if (artist == nullptr) throw std::runtime_error("Artist not found"); 
    artist->add_song(song_title, length, likes, views);//return success
}

//**********************************************************************//
//File: label.cpp
//Purpose: Contains functions that add an artist or a song; update an
//         existing song; or deletes a song based on a minumum number 
//         of views.
//**********************************************************************//
#include "label.hpp"



//**********************************************************************//
//Function: add_artist(xxx)
//Inputs:   Artist's name, description, and top story
//Outputs:  true if artist was added; false if existing
//Purpose:  This functions simply adds an artist to a list of other
//          artists.
//**********************************************************************//
bool Label::add_artist(
    char const * artist_name, 
    char const * description, 
    char const * top_story
) {
    Artist artist = Artist {artist_name, description, top_story};
    if(artists.find(artist)) return false;//if find function does not return NULL; return false.
    artists.push_front(artist);
    return true; //we did add an artist
}



//**********************************************************************//
//Function: update_song()
//Inputs:   Artist's name, song name, likes, views
//Outputs:  True if updated; false if not.
//Purpose:  This function updates the number of views and likes.
//**********************************************************************//
bool Label::update_song(
    char const * artist_name, 
    char const * song_title, 
    int likes, 
    int views
) {
    Artist* artist = artists.find(Artist{ artist_name, nullptr, nullptr });
    if (artist == nullptr) return false;
    return artist->update_song(song_title, likes, views);//return success
}



//**********************************************************************//
//Function: cull(int minimum_views)
//Inputs:   An intiger value of minimum views
//Outputs:  void
//Purpose:  To remove a song that does not exceed the view threshold. 
//**********************************************************************//
void Label::cull(int minimum_views){

}



//**********************************************************************//
//Function: add_song(xxx)
//Inputs:   Artist's name, song name, length, likes, views.
//Outputs:  True if updated; false if not.
//Purpose:  To add a new song to the list.
//**********************************************************************//
bool Label::add_song(
        char const * artist_name,    
        char const * song_name,
        float length,
        int likes,
        int views
) {

}

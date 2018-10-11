//**********************************************************************//
//File: label.hpp
//Purpose:  
//**********************************************************************//
#ifndef LABEL_HPP
#define LABEL_HPP

#include "list.hpp"
#include "artist.hpp"

struct Label{
    Label(char const * fileName);
    ~Label();
    
    void add_artist(
        char const * artist_name, 
        char const * description, 
        char const * top_story
    );
    void update_song(
        char const * artist_name, 
        char const * song_title, 
        int likes, 
        int views
    );

    void cull(int minimum_views);

    void add_song(
        char const * artist_name,    
        char const * song_title,
        float length,
        int likes,
        int views
    );

private:
    List<Artist> artist_list; //Label has a member variable of type list
};
#endif

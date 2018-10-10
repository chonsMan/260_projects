#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "list.hpp"

struct Song {
    char const * title;
    float length;
    int views, likes;

    bool operator ==(Song const & rhs) const; 
};

struct Artist {
    Artist(char const* name, char const * description, char const * top_story)
        : name(name), description(description), top_story(top_story){};

    void cull(int minimum_views);
    bool update_song(char const* song_title, int likes, int views);//don't modify song_title 
    bool operator ==(Artist const & rhs) const; 
        

private:
    char const * name, * top_story, * description;
    List<Song> songs;
};

#endif

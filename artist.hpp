#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "list.hpp"

struct song {
    char * title;
    float length;
    int views, likes;
}

struct artist {
    artist(char const * filename);
    ~artist();
    
    void addSong(song s);
    void editSong(char const * name, int likes, int views);
    void cull(int minimum_views);

private:
    char *name, *topStory, *description;
    list songs;
}

#endif

#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "list.hpp"

struct Song {
    char * title;
    float length;
    int views, likes;
};

struct Artist {
    Artist(char * name, char * description, char * top_story)
        : name(name), description(description), top_story(top_story){};
    

private:
    char *name, *top_story, *description;
    List<Song> songs;
};

#endif

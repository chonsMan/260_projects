#ifndef LABEL_HPP
#define LABEL_HPP

#include "list.hpp"
#include "artist.hpp"

struct Label{
    Label(char const * fileName);
    ~Label();
    
    bool add_artist(
        char * name, 
        char * description, 
        char * top_story
    );
    bool update_song(
        char const* artist, 
        char const * name, 
        int likes, 
        int views
    );

    void cull(int minimum_views);

    bool add_song(
        char * artist,    
        char * name,
        float length,
        int likes,
        int views
    );

private:
    List<Artist> artists; //Label has a member variable of type list
};
#endif

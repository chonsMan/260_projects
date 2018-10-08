#include "label.hpp"


bool Label::add_artist(
    char * name, 
    char * description, 
    char * top_story
) {
    Artist artist = Artist {name, description, top_story};
    if(artists.find(artist)) return false;//if find function does not return NULL; return false.
    artists.push_front(artist);
    return true; //we did add an artist
}

bool Label::update_song(
    char const* artist, 
    char const * name, 
    int likes, 
    int views
) {

}
void Label::cull(int minimum_views){

}

bool Label::add_song(
        char * artist,    
        char * name,
        float length,
        int likes,
        int views
) {

}

#include "artist.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


void Artist::cull(int minimum_views){
    songs.filter(
        [=](Song const & song){//pass by value
            return song.views >= minimum_views;//
        }
    );
}


bool Artist::update_song(char const* song_title, int likes, int views){
    Song* song = songs.find(Song{ song_title, 0, 0, 0 });
    if (song == nullptr) return false;
    song->likes = likes;
    song->views = views;
    return true;
}




bool Song::operator == (Song const & rhs) const {
    return std::strcmp(title, rhs.title) == 0;//return distance between different chars; zero if equal
}



bool Artist::operator == (Artist const & rhs) const {
    return std::strcmp(name, rhs.name) == 0;//return distance between different chars; zero if equal
} 

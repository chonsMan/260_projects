#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "list.hpp"

struct Song {
    char const * title;
    float length;
    int views, likes;
    static Song dummy(char const* title);
    static Song parse(std::istream& stream);

    bool operator ==(Song const & rhs) const; 

private:
    const static size_t BUFF_LEN = 512;
    static char* buffer;
    
};

struct Artist {
    Artist(char const* name, char const * description, char const * top_story)
        : name(name), description(description), top_story(top_story){};

    void add_song(
        char const * song_title,
        float length,
        int likes,
        int views
    );
    void cull(int minimum_views);
    void update_song(char const* song_title, int likes, int views);//don't modify song_title 
    static Artist parse(std::istream& stream);

    bool operator ==(Artist const & rhs) const; 
        
    friend std::ostream& operator << (std::ostream & lhs, Artist & rhs);
private:
    Artist() = default; //default constructor for parse

    const static size_t BUFF_LEN = 512;
    static char* buffer;

    char const * name, * top_story, * description;
    List<Song> song_list;
};

#endif

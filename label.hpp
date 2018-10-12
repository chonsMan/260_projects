//**********************************************************************//
//File: label.hpp
//Purpose:
//**********************************************************************//
#ifndef LABEL_HPP
#define LABEL_HPP

#include "list.hpp"
#include "artist.hpp"

struct Label{
    Label() = default;
    ~Label() = default;

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

    friend std::ostream & operator<<(std::ostream & stream, Label const & label);

private:
    List<Artist> artist_list;
};
#endif

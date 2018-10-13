//**********************************************************************//
//File: label.hpp
//Purpose: This serves as the top layer where the user will interact. It
//		   houses functions that add an artist, update ad existing artist,
//		   cull a song with less than a certain number of views, and
//		   adds a song to a linked list. In addition, this sturct defines
//		   operator overload for the cout functionality. It has a private
//         member variable, artist_list, to store the artists.
//**********************************************************************//
#ifndef LABEL_HPP
#define LABEL_HPP

#include "list.hpp"
#include "artist.hpp"

struct Label{
    Label() = default;
    Label(Label const & rhs) = delete;
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

    friend std::ostream & operator<<(std::ostream & stream, Label const & label); //operator overload for cout.
    friend std::istream & operator>>(std::istream & stream, Label & label); //operator overload for cout.

private:
    void add_artist(Artist * artist);
    List<Artist> artist_list; //stores artists in a list, of type artist.
};
#endif

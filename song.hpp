//**********************************************************************//
//   File: song.hpp
//Purpose: Houses the Song struct, which holds the information on each
//		   song from a particular artist.
//**********************************************************************//
#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <cstring>

struct Song {
    Song() = default;
    Song(char const * title, float length, int views, int likes);
    static Song dummy(char const* title);
    static Song parse(std::istream & stream);
    ~Song();

    char const * get_title() const;
    float get_length() const;
    int get_likes() const;
    int get_views() const;

    bool operator==(Song const & rhs) const;
    friend std::ostream & operator<<(std::ostream & lhs, Song const & rhs);

private:
    char const * title;
    float length;
    int views, likes;
};

#endif

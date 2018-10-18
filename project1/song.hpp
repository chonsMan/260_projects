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
    Song(Song const & rhs) = delete;
    Song(char const * title);
    Song(char const * title, float length, int views, int likes);
    ~Song();

    char const * get_title() const;
    float get_length() const;
    int get_likes() const;
    int get_views() const;

    bool operator==(Song const & rhs) const;
    friend std::ostream & operator<<(std::ostream & stream, Song const & song);
    friend std::istream & operator>>(std::istream & stream, Song & song);

private:
    char const * title;
    float length;
    int views, likes;
};

#endif

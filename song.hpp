#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <cstring>

struct Song {
    char const * title;
    float length;
    int views, likes;

    static Song dummy(char const* title);
    static Song parse(std::istream & stream);

    bool operator==(Song const & rhs) const;
    friend std::ostream & operator<<(std::ostream & lhs, Song const & rhs);

private:
    const static size_t BUFF_LEN = 512;
    static char* buffer;
};

#endif

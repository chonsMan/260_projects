#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <cstring>

struct Song {
    char const * title { nullptr };
    float length { 0.0 };
    int views { 0 }, likes { 0 };

    Song() = default;
    Song(Song const & rhs) = delete;

    Song(Song && rhs) :
        title(rhs.title),
        length(rhs.length),
        views(rhs.views),
        likes(rhs.likes)
    {
        rhs.title = nullptr;
        rhs.length = 0.0;
        rhs.views = rhs.likes = 0;
    }

    Song(char const * const title) : title(strcpy_allocated(title)) {}

    Song(
        char const * const title,
        float const length,
        int const views,
        int const likes
    ) :
        title(strcpy_allocated(title)),
        length(length),
        views(views),
        likes(likes)
    {}

    ~Song() {
        if (title) delete[] title;
    }

    bool operator==(Song const & rhs) const {
        return std::strcmp(title, rhs.title) == 0;
    }

    void operator=(Song && rhs) {
        if (title) delete[] title;

        title = rhs.title;
        length = rhs.length;
        views = rhs.views;
        likes = rhs.likes;

        rhs.title = nullptr;
        rhs.length = 0.0;
        rhs.views = rhs.likes = 0;
    }

    static constexpr bool more_popular(Song const & rhs, Song const & lhs) {
        return lhs.views > rhs.views;
    }

    friend std::ostream & operator<<(std::ostream &, Song const &);
    friend std::istream & operator>>(std::istream &, Song &);
};

std::ostream & operator<<(std::ostream & lhs, Song const & rhs) {
    return lhs
        << rhs.title << ';'
        << rhs.length << ';'
        << rhs.views << ';'
        << rhs.likes;
}

std::istream & operator>>(std::istream & stream, Song & song) {
    song.title = getline_allocated(stream, ';');

    stream >> song.length;
    stream.ignore(); // Consume ';'
    stream >> song.views;
    stream.ignore(); // Consume ';'
    stream >> song.likes;
    stream.ignore(); // Consume '\n'

    return stream;
}

#endif

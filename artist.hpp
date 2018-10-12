#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "list.hpp"
#include "song.hpp"

struct Artist {
    Artist(char const* name, char const * description, char const * top_story);
    static Artist dummy(char const * name);
    static Artist parse(std::istream & stream);
    ~Artist();

    void cull(int minimum_views);
    void add_song(
        char const * song_title,
        float length,
        int likes,
        int views
    );
    void update_song(
        char const* song_title,
        int likes,
        int views
    );

    bool operator==(Artist const & rhs) const;
    friend std::ostream & operator<<(std::ostream & lhs, Artist const & rhs);

private:
    Artist() = default;

    const static size_t BUFF_LEN = 512;
    static char* buffer;

    char const * name, * top_story, * description;
    List<Song> song_list;
};

#endif

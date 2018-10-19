#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <utility>

#include "c_helpers.hpp"
#include "list.hpp"
#include "song.hpp"

struct Artist {
private:
    char const
        * name = nullptr,
        * top_story = nullptr,
        * description = nullptr;

    List<Song> song_list;

public:
    Artist() = default;
    Artist(Artist const & rhs) = delete;

    Artist(Artist && rhs) :
        name(rhs.name),
        top_story(rhs.top_story),
        description(rhs.description),
        song_list(std::move(rhs.song_list))
    {
        rhs.name = rhs.top_story = rhs.description = nullptr;
    }

    Artist(
        char const * const name,
        char const * const description,
        char const * const top_story
    ) :
        name(strcpy_allocated(name)),
        description(strcpy_allocated(description)),
        top_story(strcpy_allocated(top_story))
    {};

    Artist(char const * name) : name(strcpy_allocated(name)) {}

    ~Artist() {
        if (name) delete name;
        if (description) delete description;
        if (top_story) delete top_story;
    }

    void cull(int const minimum_views) {
        song_list.filter(
            [=](Song const & song) {
                return song.views >= minimum_views;
            }
        );
    }

    void add_song(Song song) {
        if (song_list.find(song)) throw std::runtime_error("Song already exists for this artist");
        song_list.insert_sort_by(std::move(song), Song::more_popular);
    }

    void update_song(char const * const title, int const likes, int const views) {
        Song original;

        try {
            original = song_list.extract(Song(title));
        } catch (std::runtime_error &) {
            throw std::runtime_error("Song not found");
        }

        original.likes = likes;
        original.views = views;

        song_list.insert_sort_by(std::move(original), Song::more_popular);
    }

    bool operator==(Artist const & rhs) const {
        return std::strcmp(name, rhs.name) == 0;
    }

    friend std::ostream & operator<<(std::ostream & stream, Artist const & artist);
    friend std::istream & operator>>(std::istream & stream, Artist & artist);
};

std::ostream & operator<<(std::ostream & stream, Artist const & artist) {
    return stream
        << '!'
        << artist.name << ';'
        << artist.description << ';'
        << artist.top_story
        << artist.song_list;
}

std::istream & operator>>(std::istream & stream, Artist & artist) {
    stream.ignore(); // Consume '!'
    artist.name = getline_allocated(stream, ';');
    artist.description = getline_allocated(stream, ';');
    artist.top_story = getline_allocated(stream, '\n');

    while (stream.peek() != '!' && stream.peek() != -1) {
        Song song;
        stream >> song;
        artist.add_song(std::move(song));
    }

    return stream;
}
#endif

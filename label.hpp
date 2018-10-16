#ifndef LABEL_HPP
#define LABEL_HPP

#include "list.hpp"
#include "artist.hpp"

struct Label{
    Label() = default;
    Label(Label const & rhs) = delete;
    Label(Label && label) : artist_list(std::move(label.artist_list)) {}
    ~Label() = default;

    void add_artist(
        char const * artist_name,
        char const * description,
        char const * top_story
    ) {
        add_artist(Artist { artist_name, description, top_story });
    }

    void update_song(
        char const * artist_name,
        char const * song_title,
        int likes,
        int views
    ) {
        Artist * const artist { artist_list.find(Artist(artist_name)) };
        if (!artist) throw std::runtime_error("Artist not found");
        artist->update_song(song_title, likes, views);
    }

    void cull(int const minimum_views) {
        artist_list.for_each(
            [=](Artist & artist){
                artist.cull(minimum_views);
            }
        );
    }

    void add_song(
        char const * artist_name,
        char const * song_title,
        float length,
        int likes,
        int views
    ) {
        Artist * const artist { artist_list.find(Artist(artist_name)) };
        if (!artist) throw std::runtime_error("Artist not found");
        artist->add_song(Song { song_title, length, views, likes });
    }

    friend std::ostream & operator<<(std::ostream & stream, Label const & label) {
        return stream << label.artist_list;
    }

    friend std::istream & operator>>(std::istream & stream, Label & label) {
        while (stream.peek() != -1) {
            Artist artist;
            stream >> artist;
            label.add_artist(std::move(artist));
        }

        return stream;
    }

private:
    void add_artist(Artist artist) {
        if(artist_list.find(artist)) throw std::runtime_error("Artist already exists");
        artist_list.push_front(std::move(artist));
    }

    List<Artist> artist_list;
};
#endif

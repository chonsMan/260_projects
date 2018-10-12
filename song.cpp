#include "song.hpp"
#include "list.hpp"
#include "c_helpers.hpp"

//**********************************************************************//
//Function: List<song>::insert_sort(Song song)
//Inputs:  A song of type Song.
//Outputs: void
//Purpose: The purpose of this function is to take a song and insert it
//         in the proper order. For this case, the songs are arracnged
//         in the order of their popularity. Specialization to avoid
//         the need for a higher-order function.
//**********************************************************************//
template <> //template function with no undefined types; previously T was undefined
void List<Song>::insert_sort(Song song){
    List<Song>::Node * song_node = new List<Song>::Node { song, nullptr };

    if(!head){
       head = song_node;
       return;
    }

    List<Song>::Node
        ** prev = &head, //previosu contains the address of head
        * iter = head; //start at the front

    while(iter && iter->data.views > song.views) {
        prev = &iter->next; //point at the pointer
        iter = iter->next; //moves to the next node
    }

    song_node->next = iter;
    *prev = song_node;
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:  Song factory.
//**********************************************************************//
Song Song::dummy(char const* title){
    return Song { title, 0, 0, 0 };
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:  Song factory.
//**********************************************************************//
Song Song::parse(std::istream & stream) {
    Song song;

    song.title = getline_allocated(stream, ';');

    stream >> song.length;
    stream.get();
    stream >> song.views;
    stream.get();
    stream >> song.likes;
    stream.get();

    return song;
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:  Song factory.
//**********************************************************************//
bool Song::operator==(Song const & rhs) const {
    // strcmp returns distance between different chars; zero if equal
    return std::strcmp(title, rhs.title) == 0;
}

std::ostream & operator<<(std::ostream & lhs, Song const & rhs) {
    return lhs
        << rhs.title << ';'
        << rhs.length << ';'
        << rhs.views << ';'
        << rhs.likes << '\n';
}

// Static initializer
char * Song::buffer = new char[Song::BUFF_LEN];

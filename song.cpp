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
void List<Song>::insert_sort(Song * song){
    List<Song>::Node * song_node = new List<Song>::Node { song, nullptr };

    if(!head){
       head = song_node;
       return;
    }

    List<Song>::Node
        ** prev = &head, //previosu contains the address of head
        * iter = head; //start at the front

    while(iter && iter->data->get_views() > song->get_views()) {
        prev = &iter->next; //point at the pointer
        iter = iter->next; //moves to the next node
    }

    song_node->next = iter;
    *prev = song_node;
}

Song::Song(char const * title, float length, int views, int likes)
    : title(strcpy_allocated(title)), length(length), views(views), likes(likes) {}

//**********************************************************************//
//Function: Song::parse(std::istream &)
//Inputs: input stream starting with serialized song
//Outputs: parsed song
//Purpose: Dummy song factory.
//**********************************************************************//
Song::Song(char const* title) : title(strcpy_allocated(title)) {}

Song::~Song() {
    if (title) delete title;
    title = nullptr;
}

//**********************************************************************//
//Function: Member getters
//Inputs: void
//Outputs: Fields
//Purpose: Access Song data members
//**********************************************************************//
char const * Song::get_title() const { return title; }
float Song::get_length() const { return length; }
int Song::get_views() const { return views; }
int Song::get_likes() const { return likes; }

//**********************************************************************//
//Function: Song::operator==(Song const &) const
//Inputs: Song to compare
//Outputs: Equality as boolean
//Purpose: Compare songs by title
//**********************************************************************//
bool Song::operator==(Song const & rhs) const {
    // strcmp returns distance between different chars; zero if equal
    bool result = std::strcmp(title, rhs.title) == 0;
    return result;
}

std::ostream & operator<<(std::ostream & lhs, Song const & rhs) {
    return lhs
        << rhs.title << ';'
        << rhs.length << ';'
        << rhs.views << ';'
        << rhs.likes;
}

//**********************************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose: Parse song from input stream
//**********************************************************************//
std::istream & operator>>(std::istream & stream, Song & song) {
    song.title = getline_allocated(stream, ';');

    stream >> song.length;
    stream.get(); // Consume ';'
    stream >> song.views;
    stream.get(); // Consume ';'
    stream >> song.likes;
    stream.get(); // Consume '\n'

    return stream;
}

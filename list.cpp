//**********************************************************************//
//File: list.cpp
//Purpose: This file contains functions that are used to add data, find
//         data and sort data. 
//**********************************************************************//
#include "list.hpp"
#include "artist.hpp"
#include <iostream>


//**********************************************************************//
//Function: List::Node::Node(T data, Node<T>* next )
//Inputs: 
//Outputs:
//Purpose: 
//**********************************************************************//
template <typename T>
List<T>::Node::Node(T data, List<T>::Node* next )
    : data(data), next(next) {} //initializes value and the next pointer


//**********************************************************************//
//Function: List::Node::~Node()
//Inputs: 
//Outputs:
//Purpose: 
//**********************************************************************//
template <typename T>
List<T>::Node::~Node(){ //deconstructor for Node by recursion
    if (next == nullptr) return;
    delete next;
}



//**********************************************************************//
//Function: List::Node::~Node()
//Inputs: 
//Outputs:
//Purpose: 
//**********************************************************************//
template <typename T>
List<T>::~List(){ //deconstructor for List by recursion
    if (head == nullptr) return;
    delete head;
}

//**********************************************************************//
//Function: void List<T>::push_front(T data)
//Inputs: T data from the Node struct
//Outputs: void
//Purpose: The purpose of this function is to push a node (such as an 
//         artist) to the front of the list.
//**********************************************************************//
template <typename T>
void List<T>::push_front(T data){
    List<T>::Node* newNode  = new List<T>::Node(data, head);//if head is NULL, then function terminates
    head = newNode; 
} 



//**********************************************************************//
//Function: List<song>::insert_sort(Song song)
//Inputs:  A song of type Song. This is a node.
//Outputs: void
//Purpose: The purpose of this function is to take a song and insert it 
//         in the proper order. For this case, the songs are arracnged
//         in the order of their popularity.
//**********************************************************************//
template <> //template function; but no undefined types; previously T had been undefined
void List<Song>::insert_sort(Song song){
    List<Song>::Node * song_node = new List<Song>::Node(song, nullptr);

    if(head == nullptr){
       head = song_node;
       return;
    }//if

    List<Song>::Node** prev = &head;//previosu contains the address of head
    List<Song>::Node* iter = head; //start at the front
    while(iter != nullptr && iter->data.views > song.views) {
        prev = &iter->next; //point at the pointer
        iter = iter->next; //moves to the next node
    }

    song_node->next = iter; 
    *prev = song_node; 
}



//**********************************************************************//
//Function: T * Node<T>::find(T const& rhs)
//Inputs:   rhs is the right hand sid of the equivalency to be passed
//Outputs:
//Purpose: Search a node or following nodes for a value.
//**********************************************************************//
template<typename T>
T * List<T>::Node::find(T const& rhs) {
    if (data == rhs) return &data;//if found, return address of data
    if (next == nullptr) return nullptr; //if at end and not found
    return next->find(rhs); //use recursion to find next argument
}



//**********************************************************************//
//Function: T * List<T>::find(T const& rhs)
//Inputs:   rhs is the right hand side of the equivalency to be passed
//Outputs:
//Purpose: Search a list for a value.
//**********************************************************************//
template<typename T> 
T * List<T>::find(T const& rhs) {
    if (head == nullptr) return nullptr;
    return head->find(rhs);
}




//*************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:
//*************************************************//
template<typename T>
void List<T>::filter(std::function<bool(T const &)> predicate){
    List<Song>::Node** prev = &head;//previosu contains the address of head
    List<Song>::Node* iter = head; //start at the front
    while(iter != nullptr) {
        bool keep = predicate(iter->data);//predicate will tell us if the node will be kept or deleted
        if (!keep){
            *prev = iter->next;
            iter->next = nullptr;
            delete iter;
            iter = *prev;
            continue; //short-circuit back to the top of the loop
        }//if

        prev = &iter->next; //point at the pointer
        iter = iter->next; //moves to the next node
    }
} 


//*************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:
//*************************************************//
template<typename T>
void List<T>::for_each(std::function<void(T&)> funcy){
    for (List<Song>::Node* iter = head; iter != nullptr; iter = iter->next) {
        funcy(iter->data);
    }//for
}


//*************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:
//*************************************************//
template<typename T>
T List<T>::remove(T const& rhs){
    List<Song>::Node** prev = &head;//previosu contains the address of head
    List<Song>::Node* iter = head; //start at the front
    while(iter != nullptr) {
        if (iter->data == rhs){
            *prev = iter->next;
            iter->next = nullptr; //snip connection from current element
            T data = iter->data;
            delete iter;
            return data;
        }//if

        prev = &iter->next; //point at the pointer
        iter = iter->next; //moves to the next node
    }
    throw std::runtime_error("Item not found.");
}



//*************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:
//*************************************************//
template<typename T> //becomes type T
std::ostream& operator << (std::ostream& out, List<T>& list) {
	auto* p = list.head;
	for(;p!=0; p = p->next)
		out << p->data;
	out<<std::endl;
	return out;
}

template struct List<Song>; //Need to instantiate templates within same translation unit; or else unlinkable

//**********************************************************************//
//File: list.cpp
//Purpose: This file contains functions that are used to add data, find
//         data and sort data. 
//**********************************************************************//
#include "list.hpp"
#include "artist.hpp"
#include <iostream>



//**********************************************************************//
//Function: void List<T>::push_front(T data)
//Inputs: T data from the Node struct
//Outputs: void
//Purpose: The purpose of this function is to push a node (such as an 
//         artist) to the front of the list.
//**********************************************************************//
template <typename T>
void List<T>::push_front(T data){
    Node<T>* newNode  = new Node<T>(data, head);//if head is NULL, then function terminates
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

}



//**********************************************************************//
//Function: T * Node<T>::find(T const& rhs)
//Inputs:   rhs is the right hand sid of the equivalency to be passed
//Outputs:
//Purpose: Used to find a node in a list of songs. 
//**********************************************************************//
template<typename T>
T * Node<T>::find(T const& rhs) {
    if (data == rhs) return &data;//if found, return address of data
    if (next == nullptr) return nullptr; //if at end and not found
    return next->find(rhs); //use recursion to find next argument
}



//**********************************************************************//
//Function: T * List<T>::find(T const& rhs)
//Inputs:   rhs is the right hand side of the equivalency to be passed
//Outputs:
//Purpose: Used to find an artist in a list.
//**********************************************************************//
template<typename T> 
T * List<T>::find(T const& rhs) {
    if (head == nullptr) return nullptr;
    return head.find(rhs);
}



//*************************************************//
//Function:
//Inputs:
//Outputs:
//Purpose:
//*************************************************//
template<typename T> //becomes type T
std::ostream& operator << (std::ostream& out, List<T>& list) {
	for(Node<T>* p = list.head; p!=0; p = p->next)
		out << p->data;
	out<<std::endl;
	return out;
} 

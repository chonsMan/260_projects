#include "list.hpp"
#include "artist.hpp"
#include <iostream>

template <typename T>
void List<T>::push_front(T data){
    Node<T>* newNode  = new Node<T>(data, head);//if head is NULL, then function terminates
    head = newNode; 
} 

template <> //template function; but no undefined types; previously T had been undefined
void List<Song>::insert_sort(Song song){

}

template<typename T>
T * Node<T>::find(T const& rhs) {
    if (data == rhs) return &data;//if found, return address of data
    if (next == nullptr) return nullptr; //if at end and not found
    return next->find(rhs); //use recursion to find next argument
}

template<typename T> 
T * List<T>::find(T const& rhs) {
    if (head == nullptr) return nullptr;
    return head.find(rhs);
}



template<typename T> //becomes type T
std::ostream& operator << (std::ostream& out, List<T>& list) {
	for(Node<T>* p = list.head; p!=0; p = p->next)
		out << p->data;
	out<<std::endl;
	return out;
} 

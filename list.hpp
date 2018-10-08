#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
template <typename T> struct Node{
    //reference to the field data, which is set to the parameter data; 
    //reference to the field next, which is set to nullptr
    Node(T data) : data(data), next(nullptr) {} //takes value
    Node(T data, Node<T>* next ) : data(data), next(next) {} //initializes value and the next pointer
    T * find(T const& rhs);
    

	T data; //Field inside node 
	Node<T> * next; //Next is a field of type node ptr
};//struct 	

template <typename T> struct List{
	List();
	~List();

    void push_front(T data); 

	void insert_sort(T data);			

    //Use pointer to return NULL if not found. 
    T * find(T const& rhs);//pass in rhs and do not modify

    template<typename U>
	friend std::ostream& operator<<(std::ostream& out, List<U>& list);
private:
	Node<T> * head;
};
#endif


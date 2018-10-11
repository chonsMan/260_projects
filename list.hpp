//**********************************************************************//
//File: list.cpp
//Purpose: This file contains functions that are used to add data, find
//         data and sort data. 
//**********************************************************************//
#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <functional>

template <typename T> struct List{
private:
    struct Node{
        Node(T data, List<T>::Node* next ); 
        ~Node();

        T * find(T const& rhs);
        T data; //Data field inside node 
        Node * next = nullptr; //Next is a field of type node ptr
    };//struct 	

public:
	~List();

    void push_front(T data); 
    //To filter we pass the address of a function
    void filter(std::function<bool(T const &)> predicate);//function pointer pred. takes a reference to a constant T  
	void insert_sort(T data);			
    T remove(T const& rhs);//Used to remove song from list for re-sort.
    //Use pointer to return NULL if not found. 
    T * find(T const& rhs);//pass in rhs and do not modify
    void for_each(std::function<void(T&)> funcy);

    template<typename U>
	friend std::ostream& operator<<(std::ostream& out, List<U>& list);

private:
	Node * head = nullptr;
};
#endif


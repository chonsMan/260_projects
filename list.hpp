//**********************************************************************//
//File:    list.hpp
//Purpose: This file contains functions that are used to add data, find
//         data and sort data. Because these fuctions are typecasted,
//         both their declaration and definition are present in this
//		   file.The purpose of the List struct is to generate a list. It does so
//		   through the use of an internal struct called Node. Node is,
//		   of course, what generates nodes to be members of the list.
//		   The Node struct is private to the List struct. Also private
//         to the list is the node pointer head.
//**********************************************************************//
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <functional>

template <typename T>
struct List {
private:
    struct Node {
        Node(T * data, List<T>::Node* next) : data(data), next(next) {}; //constructor
        Node(Node const & rhs) = delete;
        ~Node() { //destructor
            delete data;
            if (!next) return;
            delete next;
        }

        //**********************************************************************//
        //Function: T find(T const& rhs)
        //  Inputs: rhs is the right hand sid of the equivalency to be passed
        // Outputs:	Returns address of data or the next node in a list, recursively
        // Purpose: Search a node or following nodes for a value.
        //**********************************************************************//
        T * find(T const & rhs) {
            if (*data == rhs) return data; // if found, return address of data
            if (!next) return nullptr; // if at end and not found
            return next->find(rhs); // use recursion to find next argument
        }

        T * data; //Data field inside node
        Node * next = nullptr; //Next is a field of type node ptr
    };

	Node * head = nullptr;

public:
    List() = default;
    List(List const & rhs) = delete;

	void insert_sort(T * data);


    //**********************************************************************//
    //Function: ~List()
    //  Inputs: None
    // Outputs: None
    // Purpose: Destroy the list
    //**********************************************************************//
	~List() {
        if (!head) return;
        delete head;
    }



    //**********************************************************************//
    //Function: void List<T>::push_front(T data)
    //  Inputs: T data from the Node struct
    // Outputs: void
    // Purpose: The purpose of this function is to push a node (such as an
    //          artist) to the front of the list.
    //**********************************************************************//
    void push_front(T * data) {
        head = new Node { data, head };//if head is NULL, then list auto terminates
    }


	//**********************************************************************//
    //Function: void filter(std::function<bool(T const &)> predicate)
    //  Inputs:
    // Outputs:
    // Purpose: Filters the list.
    //**********************************************************************//
    void filter(std::function<bool(T const &)> predicate) {
        Node
            ** prev = &head, //previosu contains the address of head
            * iter = head; //start at the front

        while(iter) {
            bool keep = predicate(*iter->data);//predicate will tell us if the node will be kept or deleted
            if (!keep){
                *prev = iter->next;
                iter->next = nullptr;
                delete iter;
                iter = *prev;
                continue; //short-circuit back to the top of the loop
            }

            prev = &iter->next; //point at the pointer
            iter = iter->next; //moves to the next node
        }
    }


	//**********************************************************************//
    //Function: void for_each(std::function<void(T &)> funcy)
    //  Inputs:
    // Outputs:
    // Purpose:
    //**********************************************************************//
    void for_each(std::function<void(T &)> funcy) {
        for (Node* iter = head; iter; iter = iter->next)
            funcy(*iter->data);
    }



	//**********************************************************************//
    //Function: T remove(T const& rhs)
    //  Inputs:
    // Outputs: Returns data of type T or a runtime error if item not found.
    // Purpose: This function is used to "lift" a node out of a list to be able
    //          to insert data
    //**********************************************************************//
    T * remove(T const& rhs) {
        Node
            ** prev = &head, //previous contains the address of head
            * iter = head; //start at the front

        while(iter) {
            if (*iter->data == rhs){ //if we found what we are looking for
                *prev = iter->next; //deref. prev and set it equal to the next node after iter
                iter->next = nullptr; //snip connection from current element
                T * data = iter->data;  //data equals data inside current element
                iter->data = nullptr; // Prevent iter from deleting data
                delete iter; //delete element
                return data; //return the data to be used
            }

            prev = &iter->next; //point at the pointer
            iter = iter->next; //moves to the next node
        }

        throw std::runtime_error("Item not found."); //if we never find it
    }



    //**********************************************************************//
    //Function: T * find(T const& rhs)
    //  Inputs: rhs is the right hand side of the equivalency to be passed
    // Outputs:
    // Purpose: Search a list for a value. Recursive function.
    //**********************************************************************//
    T * find(T const& rhs) const {
        if (!head) {
            return nullptr;
        }
        return head->find(rhs);
    }


	//**********************************************************************//
    //Function: friend std::ostream & operator<<(std::ostream & out, List<T> const & list)
    //  Inputs: ostream operator and a reference to a list
    // Outputs:
    // Purpose:
    //**********************************************************************//
	friend std::ostream & operator<<(std::ostream & out, List<T> const & list) {
        auto * curr = list.head;

        for(; curr->next; curr = curr->next)
            out << *curr->data << '\n';

        return out << *curr->data;
    }
};

#endif

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "group.hpp"
#include <utility>

struct Queue{
    Queue();//constructor
    ~Queue();//destructor
    Queue & push(Group group); // Add to tail of list
    Group const & peek();
    Group pop(); // Pop entire group by value

private:
    struct Node{
        Node(Group group, Queue::Node * next)
            : group (std::move(group)), next(next) {}; // Constructor
        Node(Node const & rhs) = delete;
        ~Node() { // Destructor (recursive approach)
            if(!next) return; // No next pointer; exit
            delete next; //delete next pointer
        }

        Group group; // Declares the field
        Node * next = nullptr;
    }; // Struct

    Node 
        * head = nullptr,
        * tail = nullptr; 
};// Struct



#endif

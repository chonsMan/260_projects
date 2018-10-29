#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "group.hpp"
#include <utility>

struct Queue{
    Queue() = default;//constructor
    Queue(Queue const & queue) = delete;
    Queue(Queue && queue);
    ~Queue();//destructor
    Queue & push(Group group); // Add to tail of list
    bool is_empty(); // Check if queue is empty
    Group const & peek(); // Peek head
    Group pop(); // Pop entire group by value

    friend std::ostream & operator<<(
        std::ostream & output,
        Queue const & rhs 
    );  

private:
    struct Node{
        Node(Group group)
            : group (std::move(group)) {}; // Constructor
        Node(Node const & rhs) = delete;
        Node(Node && node);
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
}; // Struct
#endif 

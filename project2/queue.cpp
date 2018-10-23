#include "queue.hpp"
#include <stdexcept>

Queue::Queue(Queue && queue) : head{head}, tail{tail} {
    queue.head = queue.tail = nullptr;
}

Queue::~Queue(){
    while (!is_empty()) pop(); // Beautiful destructor
}

Queue & Queue::push(Group group){
    Node * new_node = new Node{ std::move(group) }; // Calls constructor
    if (is_empty()) {
        head = tail = new_node;
        new_node->next = head;
    }

    else {
        new_node->next = head;
        tail->next = new_node;
        tail = new_node;
    }

    return *this; // Deref this ptr to object that calls it. Returns a ref.
}

bool Queue::is_empty() { return head == nullptr; }

Group const & Queue::peek(){
    if(is_empty()) 
        throw std::length_error("Tried to peek an empty queue! ");
    return head->group;
}


Group Queue::pop(){
    if(is_empty()) 
        throw std::length_error("Tried to pop an empty queue! ");
    // Extract node
    Node * popped {head};
    // Remove node from list
    if(head == tail)
        head = tail = nullptr;
    else
        head = head->next;
    // Remove list from node
    popped->next = nullptr;
    // Get value
    Group group{ std::move(popped->group) };
    delete popped;
    return group;
}
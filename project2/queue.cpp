//File: queue.cpp
//Purpose: Constructs the queue of people for the wait list
#include "queue.hpp"
#include <stdexcept>


// Constructor
Queue::Queue(Queue && queue) : head{head}, tail{tail} {
    queue.head = queue.tail = nullptr;
}


//Destructor
Queue::~Queue(){
    while (!is_empty()) pop(); // Beautiful destructor
}


//Input: group
//Output: none
//Purpose: push a group on the queue
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


//Input: none
//Output: boolean case for checking if the list is empty
bool Queue::is_empty() { return head == nullptr; }


//Inputs: none
//Outputs: First group
//Purpose: Allows the user to peek the next group
Group const & Queue::peek(){
    if(is_empty()) 
        throw std::length_error("Tried to peek an empty queue! ");
    return head->group;
}


//Inputs: none
//Outputs: a group
//Purpose: pop a group from a list
Group Queue::pop(){
    if(is_empty()) 
        throw std::length_error("Tried to pop an empty queue! ");
    // Extract node
    Node * popped {head};
    // Remove node from list
    if(head == tail)
        head = tail = nullptr;
    else {
        head = head->next;
        tail->next = head;
    }
    // Remove list from node
    popped->next = nullptr;
    // Get value
    Group group{ std::move(popped->group) };
    delete popped;
    return group;
}


//Operator overload fo '<<' operator
std::ostream & operator<<(
    std::ostream & output,
    Queue const & rhs 
) {
    Queue::Node * iter = rhs.head;
    if (iter == nullptr) return output;
    int i = 1;

    do {
        output << "Group " << i << ": " << iter->group;
        iter = iter->next;
        i++;
    } while(iter != rhs.head);

    return output;
}
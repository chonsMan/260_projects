#include "victor.hpp"
#include <algorithm>


// user should be able to set capacity
template <typename Item>
Victor<Item>::Victor(size_t reserved) : capacity{reserved} {
    reallocate();
}



template <typename Item>
Victor<Item>::Victor(Victor<Item> const & rhs) :
    size{size}, capacity{capacity}
{
    reallocate();
    if (size > 0) {
        std::copy (
            &rhs.vodka[0],
            &rhs.vodka[rhs.size],
            &vodka[0]
        )
    }
}



template <typename Item>
Victor<Item>::Victor(Victor && rhs) :
    vodka{rhs.vodka}, size{rhs.size}, capacity{rhs.capacity}
{
    rhs.vodka = nullptr;
    rhs.size = rhs.capacity = 0;
}




template <typename Item>
Victor<Item>::~Victor(){
    if (vodka) delete[] vodka;
}



template <typename Item>
Victor<Item> & Victor<Item>::push(Item value) {
    guarantee_space();
    vodka[size] = std::move(value);
    size++;
    return *this;
}


template <typename Item>
Item Victor<Item>::pop() {
    if (size == 0) throw std::length_error("Tried to pop and empty array");
    size--;
    Item popped {std::move(vodka[size])};
    shrink_to_fit();
    return popped;
}



template <typename Item>
void Victor<Item>::guarantee_space(){
    // Have enough space
    if (capacity > size) return;
    // Empty
    if (capacity == 0) {
        resize(1);
        return;
    }
    resize(capacity*2);
}



template <typename Item>
void Victor<Item>::shrink_to_fit(){
    if (capacity == 0) return;
    if (size > capacity/4) return;
    resize(capacity/2);
}



template <typename Item>
void Victor<Item>::resize(size_t requested) {
    capacity = requested;
    Item * prev = reallocate();
    if (size > 0) {
        std::move(
            // Iterator pointing at the first element of the source
            &prev[0],
            &prev[size], // Goes off end of array (last is [size - 1])
            &vodka[0] // Pointer to the first element of the destination
        )
    }

    // Get rid of old array now that all vodka has been taken out
    if (prev) delete[] prev;
}


template <typename Item>
Item * Victor<Item>::reallocate(){
    Item * prev = vodka;
    //Allocate a new array using the size that is in capacity
    vodka = capacity ? new Item[capacity] : nullptr;
    return prev;
}



// Allows for access to Victor at specified index as if raw array
template <typename Item> 
Item & Victor<Item>::operator[](size_t const index) {
    return vodka[index];
}

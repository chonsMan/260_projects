#ifndef VICTOR_HPP
#define VICTOR_HPP
#include <cstddef>
#include <utility>
#include <algorithm>
#include <stdexcept>

template<typename Item>
struct Victor{
    Victor() = default;

    Victor(size_t reserved) : capacity{reserved} { reallocate(); }


    Victor(Victor const & rhs) :
        size{rhs.size},
        capacity{rhs.capacity}
    {
        reallocate();
        if (size > 0) {
            std::copy (
                &rhs.vodka[0],
                &rhs.vodka[rhs.size],
                &vodka[0]
            );
        }
    }

    Victor(Victor && rhs) :
        vodka{rhs.vodka},
        size{rhs.size},
        capacity{rhs.capacity}
    {
        rhs.vodka = nullptr;
        rhs.size = rhs.capacity = 0;
    }

    ~Victor() { if (vodka) delete[] vodka; }

    size_t get_size() const { return size; }


    void push(Item value) { // Provide a fluent API
        guarantee_space();
        vodka[size] = std::move(value);
        size++;
    }

    Item pop() {
        if (size == 0) throw std::length_error("Tried to pop and empty array");
        size--;
        Item popped {std::move(vodka[size])};
        shrink_to_fit();
        return popped;
    }

    Item & operator[](size_t index) {
        return vodka[index];
    }

    // Different type parameter in order to have char and int
    template <typename RhsItem>
    bool operator==(Victor<RhsItem> const & rhs) const {
        if (size != rhs.size) return false;
        for(size_t i{0}; i < size; i++) {
            if(vodka[i] != rhs.vodka[i]) return false;
        }
        return true;
    }

protected:
    Item * vodka = nullptr;
    size_t size = 0, capacity = 0;

    // Internals
    void guarantee_space() { // When it returns, guaranteed enough space
        // Have enough space
        if (capacity > size) return;
        // Empty
        if (capacity == 0) {
            resize(1);
            return;
        }
        resize(capacity*2);
    }
    void shrink_to_fit() {   // Shrink by half is 1/4 capacity
        if (capacity == 0) return;
        if (size > capacity/4) return;
        resize(capacity/2);
    }

    void resize(size_t requested) {    // Resizes to number passed in
        capacity = requested;
        Item * prev = reallocate();
        if (size > 0) {
            std::move(
                // Iterator pointing at the first element of the source
                &prev[0],
                &prev[size], // Goes off end of array (last is [size - 1])
                &vodka[0] // Pointer to the first element of the destination
            );
        }

        // Get rid of old array now that all vodka has been taken out
        if (prev) delete[] prev;
    }

    Item * reallocate() {    // Allocates a new array having capacity # of elements and returns the old one
        Item * prev = vodka;
        //Allocate a new array using the size that is in capacity
        vodka = capacity ? new Item[capacity] : nullptr;
        return prev;
    }
};

#endif

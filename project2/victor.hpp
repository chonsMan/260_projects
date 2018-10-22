#ifndef VICTOR_HPP
#define VICTOR_HPP
#include <cstddef>

template<typename Item>
struct Victor{
    Victor() = default;
    Victor(size_t reserved);
    Victor(Victor const & rhs);
    Victor(Victor && rhs);
    ~Victor();

    Victor & push(Item value); // Provide a fluent API
    Item pop();
    Item & operator[](size_t);

protected:
    Item * vodka = nullptr;
    size_t size = 0, capacity = 0;

    // Internals
    void guarantee_space(); // When it returns, guaranteed enough space
    void shrink_to_fit();   // Shrink by half is 1/4 capacity
    void resize(size_t);    // Resizes to number passed in
    Item * reallocate();    // Allocates a new array having capacity # of elements and returns the old one
};

#endif
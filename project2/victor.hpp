#ifndef VICTOR_HPP
#define VICTOR_HPP
#include <cstddef>

template<typename Item>
struct Victor{
    Victor() = default;
    Victor(Victor const & rhs);
    Victor(Victor && rhs);
    ~Victor();

private:
    Item * vodka = nullptr;
    size_t size = 0, capacity = 0;
}

#endif
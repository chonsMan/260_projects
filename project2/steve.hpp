#ifndef STEVE_HPP
#define STEVE_HPP
#include<cstring>

struct Steve {
    Steve() = default;
    // Copy is default b/c it will just copy over Victor
    Steve(Steve const & rhs) = default;
    Steve(Steve && rhs);
    // Victor goes out of scope and will call its own destructor
    ~Steve() = default;
private:
    Victor victor;
}

#endif
//**********************************************************************//
//   File: c_helpers.hpp
//Purpose: Used for file i/o.
//**********************************************************************//

#ifndef C_HELPERS_H
#define C_HELPERS_H

#include <iostream>

char * getline_allocated(std::istream & stream, char delimiter);

char * strcpy_allocated(char const * const source);

#endif

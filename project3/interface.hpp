
//**********************************************************************//
//   File: interface.hpp
//Purpose: houses function definition for user interface execution.
//**********************************************************************//
#ifndef INTERFACE_HPP                                                                
#define INTERFACE_HPP                                                                
                                                                                     
#include "restaurant.hpp"                                                                 
#include <iostream>                                                                  
                                                                                     
bool interface_execute(
    std::istream & input, 
    std::ostream & output, 
    Restaurant & restaurant
);                  
                                                                                     
#endif 

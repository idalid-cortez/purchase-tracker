/*
 * ======================================================================================
 * Project: StockSync: Purchase Tracking Software
 * File:    GroceryException.h
 * Author:  Ada Idalid Cortez
 * Date:    June 20th, 2026
 * Description: Header file defining the class interface and method prototypes.
 * ======================================================================================
 */

 //GUARDS
// Include guards to prevent multiple definition errors during compilation
#ifndef GROCERY_EXCEPTION_H // Verifies if the macro has not been defined yet
#define GROCERY_EXCEPTION_H // Defines the GROCERY_EXCEPTION_H macro

//LIBRARIES 
#include <stdexcept> // Provides standard exception classes like std::runtime_error
#include <string> // Provides the std::string class to store error messages

//CLASS DEFINITION
class GroceryException : public std::runtime_error { // Inherits from std::runtime_error
public:
    //CONSTRUCTOR
    // Accepts a string message by const-reference for efficiency
    explicit GroceryException(const std::string& message)
        : std::runtime_error(message) // Passes the message to the base std::runtime_error constructor
         {}
};

#endif // End of GROCERY_EXCEPTION_H macro definition
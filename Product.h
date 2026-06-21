/*
 * ======================================================================================
 * Project: StockSync: Purchase Tracking Software
 * File:    Product.h
 * Author:  Ada Idalid Cortez
 * Date:    June 20th, 2026
 * Description: Header file defining the class interface and method prototypes.
 * ======================================================================================
 */

 //GUARDS
// Include guards to prevent multiple definition errors during compilation
#ifndef PRODUCT_H // Verifies if the macro has not been defined yet
#define PRODUCT_H // Defines the PRODUCT_H macro

//LIBRARIES 
#include <string> // Provides the std::string class to store the productName

//CLASS DEFINITION
class Product {
private:
    std::string productName;
    int purchaseCount;

public:
    //CONSTRUCTOR
    Product(std::string name, int count = 0);

    //GETTERS
    std::string getName() const; //marked const because 
    int getCount() const;       //they don't modify the object

    // Logic to modify state of purchase count
    void incrementCount();
};

#endif // End of PRODUCT_H macro definition
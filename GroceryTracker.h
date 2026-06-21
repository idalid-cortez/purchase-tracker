/*
 * ======================================================================================
 * Project: StockSync: Purchase Tracking Software
 * File:    GroceryTracker.h
 * Author:  Ada Idalid Cortez
 * Date:    June 20th, 2026
 * Description: Header file defining the class interface and method prototypes.
 * ======================================================================================
 */

 //GUARDS
// Include guards to prevent multiple definition errors during compilation
#ifndef GROCERY_TRACKER_H // Verifies if the macro has not been defined yet
#define GROCERY_TRACKER_H // Defines the GROCERY_TRACKER_H macro

//LIBRARIES
#include <map> // Provides the std::map container to store items and their frequencies
#include <string> // Provides the std::string class to store the keys and process files
#include <optional> // Provides std::optional for functions that may not return a value
#include "Product.h" // Includes the custom Product class definition (needed for map storage)

class GroceryTracker {
private:
    std::map<std::string, Product> productMap;

public:
    //Constructor declaration
    GroceryTracker();
    // Process input from sales.txt
    void loadDataFromFile(const std::string& filename);

    // Save current state to a backup file
    void saveBackup(const std::string& filename) const;

    // Search for a specific product; returns empty optional if not found
    std::optional<Product> searchFor(const std::string& name) const;

    // Print histogram to console
    void printHistogram() const;
};

#endif
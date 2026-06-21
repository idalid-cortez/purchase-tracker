/*
 * ======================================================================================
 * Project: StockSync: Purchase Tracking Software
 * File:    GroceryTracker.cpp
 * Author:  Ada Idalid Cortez
 * Date:    June 20th, 2026
 * Description: Implementation file - logic and under-the-hood function processes.
 * ======================================================================================
 */

#include <iostream> //Standard input/output steam objects
#include <fstream> //File stream classes for reading and writing files
#include <string> //String class for handling product names and data manipulation
#include <filesystem> //Library to handle file paths and directories in an OS-independent way
#include <iomanip> // Essential for formatting
#include "GroceryTracker.h"
#include "GroceryException.h"


namespace fs= std::filesystem;

//==============================
// CONSTRUCTOR: IMPLEMENTATION |
//==============================

GroceryTracker::GroceryTracker() {
    // Constructor logic (empty, as the map self-initializes)
}

//==========================
// METHODS: IMPLEMENTATION |
//==========================

//FILE INPUT
void GroceryTracker::loadDataFromFile(const std::string& filename) {
    fs::path filePath = fs::path("data") / filename; //Creates platform-independent path (data: folder name)
    std::ifstream inFile(filePath);

    if (!inFile.is_open()) {
        throw GroceryException("Could not open file: " + filename);
    }

    std::string itemName;
    //Read until EOF
    while (inFile >> itemName) { //Reads file word by word
        // If it exists in map, increment; otherwise, insert
        if (productMap.find(itemName) != productMap.end()) {
            productMap.at(itemName).incrementCount(); 
                //If the item already exists, in creases purchase count
        } else {
            productMap.insert({itemName, Product(itemName, 1)}); //Call to constructor
                    //If the item didn't exist already, it adds it and sets purchase count to 1
        }
    }
    inFile.close();
}

//CREATION OF BACKUP FILE (OUTPUT)
void GroceryTracker::saveBackup(const std::string& filename)const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) throw GroceryException("Could not create backup file.");

    // Iterate through the map
    for (const auto& [name, product] : productMap) {
        outFile << name << " " << product.getCount() << std::endl;
    }
    outFile.close();
}

//SEARCH FOR A PRODUCT
std::optional<Product> GroceryTracker::searchFor(const std::string& name) const {
    auto itr = productMap.find(name); //Call to optimized search function
    if (itr != productMap.end()) {
        return itr->second;
    }
    return std::nullopt; // Return "nothing" if not found
}

//PRINT PURCHASE COUNT HISTOGRAM
void GroceryTracker::printHistogram() const {
    for (const auto& [name, product] : productMap) { //Key and value (not attributes)
        // 1. Print the name with fixed width (e.g., 15 characters)
        // 2. std::left aligns the text to the left of that space
        std::cout << std::left << std::setw(15) << name << " ";

        // 3. Print the asterisks
        for (int i = 0; i < product.getCount(); ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

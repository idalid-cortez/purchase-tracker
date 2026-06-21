/*
 * ======================================================================================
 * Project: StockSync: Purchase Tracking Software
 * File:    Main.cpp
 * Author:  Ada Idalid Cortez
 * Date:    June 20th, 2026
 * Description: Application entry point. Coordinates user input, manages 
 * the main control loop, and invokes GroceryTracker methods 
 * to process requests.
 * ======================================================================================
 */
#include <iostream>
#include "GroceryTracker.h"

// Enum for better readability
enum class MenuOption {
    Search = 1,
    PrintHistogram,
    SaveBackup,
    Exit
};

void displayMenu() {
    std::cout << "\n\n==== Grocery Tracker Menu ====\n\n";
    std::cout << "1. Search for an item\n\n";
    std::cout << "2. Print histogram\n\n";
    std::cout << "3. Save backup\n\n";
    std::cout << "4. Exit\n\n\n";
    std::cout << "Selection: ";
}

int main() {
    GroceryTracker tracker;
    tracker.loadDataFromFile("sales.txt"); // Load initial data

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        //Cast the integer to enum class
        MenuOption option = static_cast<MenuOption>(choice);

        switch (option) {
            case MenuOption::Search: {
                std::string productName;
                std::cout << "\n\nWelcome to the product search!\n\n";
                std::cout << "Name of product: ";
                std::cin >> productName;

                //Capture the result from the tracker
                auto result = tracker.searchFor(productName);

                //Check if the result exists (using the optional)
                if (result.has_value()) {
                    // Access the product using .value() or the * operator
                    std::cout << "\n\nFound: " << result->getName() 
                            << " - Purchased: " << result->getCount() << " times." << std::endl;
                } else {
                    std::cout << "\n\nSorry, that product was not found." << std::endl;
                }
                break;
            }
            case MenuOption::PrintHistogram:
                std::cout<<"\n\n===HISTOGRAM OF PURCHASES===\n"<<std::endl;
                tracker.printHistogram();
                break;
            case MenuOption::SaveBackup:
                tracker.saveBackup("frequency.dat");
                break;
            case MenuOption::Exit:
                std::cout << "\n\nExiting...\n";
                break;
            default:
                std::cout << "\n\nInvalid choice, please try again.\n";
        }
    } while (choice != 4); 

    return 0;
}
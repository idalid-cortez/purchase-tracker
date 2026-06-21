/*
 * ======================================================================================
 * Project: StockSync: Purchase Tracking Software
 * File:    Product.cpp
 * Author:  Ada Idalid Cortez
 * Date:    June 20th, 2026
 * Description: Implementation file -logic and under-the-hood function processes.
 * ======================================================================================
 */

 #include<string>
 #include "Product.h"

//==============================
// CONSTRUCTOR: IMPLEMENTATION |
//==============================

//Member initializer list
Product::Product(std::string _productName, int _purchaseCount)
            : productName(_productName), purchaseCount(_purchaseCount) {

}
//==========================
// METHODS: IMPLEMENTATION |
//==========================

//GETTERS
//const to prevent accidental modifications
std::string Product::getName() const {
    return productName;
}
int Product::getCount() const {
    return purchaseCount;
}
//INCREMENT COUNT
void Product::incrementCount() {
    purchaseCount++;
}
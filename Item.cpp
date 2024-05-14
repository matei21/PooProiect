#include "./Item.h"
#include <iostream>
#include <cstring>

//basic constructors
Item::Item() : itemPrice(0){

}
Item::Item(char* name_, int price_) : itemName(name_), itemPrice(price_){

}

//basic getters
int Item::getPrice() const {
    long int priceDouble = this->itemPrice;
    return priceDouble;
}

char* Item::getItemName(){
    char* toRet = new char[strlen(itemName)];
    strcpy(toRet, itemName);
    return toRet;
}

//basic print
void Item::printItem(){
    std::cout << "Name: " << itemName << ", " <<
       itemPrice << " lei\n";
}

//operator<< overload
std::ostream& operator<<(std::ostream& os, Item& item){
    item.printItem();
    return os;
}

// copy constructor
Item::Item(const Item& other) 
    : itemPrice(other.itemPrice) {
    if (other.itemName) {
        itemName = new char[strlen(other.itemName) + 1];
        strcpy(itemName, other.itemName);
    } else {
        itemName = nullptr;
    }

    if (other.storeBelong) {
        storeBelong = new char[strlen(other.storeBelong) + 1];
        strcpy(storeBelong, other.storeBelong);
    } else {
        storeBelong = nullptr;
    }
}

//operator=
Item& Item::operator=(const Item& other){
    if (this != &other) {
        delete[] itemName;
        delete[] storeBelong;

        if (other.itemName) {
            itemName = new char[strlen(other.itemName) + 1];
            strcpy(itemName, other.itemName);
        } else {
            itemName = nullptr;
        }

        if (other.storeBelong) {
            storeBelong = new char[strlen(other.storeBelong) + 1];
            strcpy(storeBelong, other.storeBelong);
        } else {
            storeBelong = nullptr;
        }

        itemPrice = other.itemPrice;
    }
    return *this;
}

//destructor which frees the dynamically allocated memory
Item::~Item(){
   delete[] itemName;
   delete[] storeBelong;
}
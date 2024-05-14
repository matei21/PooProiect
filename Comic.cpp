#include "./Comic.h"
#include <iostream>

//basic constructor
Comic::Comic() : Item(){
    this->condition = "Fine";
}

//only the condition differs from the Item class so we'll let the Item constructor handle the name and price
Comic::Comic(char* name_, int price_, std::string condition_) : Item(name_, price_){
    this->condition = condition_;
}

//copy constructor 
Comic::Comic(const Comic& other) : Item(other){
    this->condition = other.condition;
}

//setter for the store name
void Comic::setStoreName(char* nameToSet){
    this->storeBelong = nameToSet;
}

//getter for the store name
std::string Comic::getStoreBelongName(){
    return this->storeBelong;
}

std::string Comic::getCondition(){
    return this->condition;
}


//operator=, we don't know if we'll use it but it's good to have it
Comic& Comic::operator=(Comic& other){
    if(this != &other){
        delete[] itemName;
        delete[] storeBelong;
        if(other.itemName){
            itemName = new char[strlen(other.itemName) + 1];
            strcpy(itemName, other.itemName);
        }else{
            itemName = nullptr;
        }
        if(other.storeBelong){
            storeBelong = new char[strlen(other.storeBelong) + 1];
            strcpy(storeBelong, other.storeBelong);
        }else{
            storeBelong = nullptr;
        }
    }
    return *this;
}

//operator<<, we could also use the Item operator<< or displayItem() but it's good to have it
std::ostream& operator<<(std::ostream& os, const Comic& com){
    os << "Name: " << com.itemName << ", " <<
       com.itemPrice << " lei in the condition of: " << com.condition << '\n';
    return os;
}
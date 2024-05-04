#include "./Comic.h"
#include <iostream>
Comic::Comic() : Item(){
    this->condition = "Fine";
}
Comic::Comic(char* name_, int price_, std::string condition_) : Item(name_, price_){
    // this->comicName = name_;
    // this->comicPrice = price_;
    this->condition = condition_;
}

Comic::Comic(const Comic& other) : Item(other){
    this->condition = other.condition;
}

void Comic::setStoreName(char* nameToSet){
    this->storeBelong = nameToSet;
}

std::string Comic::getStoreBelongName(){
    return this->storeBelong;
}

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

std::ostream& operator<<(std::ostream& os, const Comic& com){
    os << "Name: " << com.itemName << ", " <<
       com.itemPrice << " lei in the condition of: " << com.condition << '\n';
    return os;
}
#include "./Comic.h"
#include <iostream>
Comic::Comic(){

}
Comic::Comic(std::string name_, int price_, std::string condition_) {
    this->comicName = name_;
    this->comicPrice = price_;
    this->condition = condition_;
}

//TODO condition name checked
long int Comic::getComicPrice() const {
    long int comicPriceDouble = comicPrice;
    return comicPriceDouble;
}

void Comic::setStoreName(std::string nameToSet) {
    this->storeBelong = nameToSet;
}

std::ostream& operator<<(std::ostream& os, const Comic& com){
    os << "Name: " << com.comicName << ", " <<
       com.comicPrice << " lei in the condition of: " << com.condition << '\n';
    return os;
}
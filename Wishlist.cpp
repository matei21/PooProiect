#include "./Wishlist.h"
#include <iostream>
void Wishlist::addToWishlist(int id, Item *item) {
    wishlist[wishlist.size()+1] = item;
    priceToBePaid += item->getPrice();
}

void Wishlist::removeFromWishlist(int id) {
    wishlist.erase(id);
}

bool Wishlist::isWishListEmpty(){
    return wishlist.size() == 0;
}

int Wishlist::getSize(){
    return wishlist.size();
}

int Wishlist::getPrice(){
    return priceToBePaid;
}

void Wishlist::printWishlist(){
    for(auto it = wishlist.begin(); it != wishlist.end(); it++){
        std::cout << it->second << '\n';
    }
}
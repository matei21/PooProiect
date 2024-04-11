#include "./Wishlist.h"
#include <iostream>
void Wishlist::addToWishlist(int id, Comic &comic) {
    wishlist.insert({wishlist.size()+1, comic});
    priceToBePaid += comic.getComicPrice();
}

void Wishlist::removeFromWishlist(int id) {
    wishlist.erase(id);
}

void Wishlist::printWishlist() {
    std::cout << "\nThe Wishlist, with a total price of" << priceToBePaid << ": \n";
    for(auto i : wishlist){
        std::cout << "ID: " << i.first << ' ';
        std::cout << i.second;
        std::cout << '\n';
    }
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
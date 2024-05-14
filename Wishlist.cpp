#include "./Wishlist.h"
#include <iostream>

//we can add a generic Item to the wishlist
void Wishlist::addToWishlist(int id, Item *item) {
    wishlist[wishlist.size()+1] = item;
    priceToBePaid += item->getPrice();
}


//we can remove something from the wishlist using the id, this is useful for the ComicWishlist
void Wishlist::removeFromWishlist(int id) {
    wishlist.erase(id);
}

//simple bool function to check if the wishlist is empty
bool Wishlist::isWishListEmpty(){
    return wishlist.size() == 0;
}

//basic getters
int Wishlist::getSize(){
    return wishlist.size();
}

int Wishlist::getPrice(){
    return priceToBePaid;
}

//basic print function
void Wishlist::printWishlist(){
    for(auto it = wishlist.begin(); it != wishlist.end(); it++){
        std::cout << it->second << '\n';
    }
}
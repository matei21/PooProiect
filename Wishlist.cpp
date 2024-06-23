#include "./Wishlist.h"
#include <iostream>


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
    std::for_each(wishlist.begin(), wishlist.end(), [](const auto& item) {
        std::cout << *item.second << '\n';
    });
}
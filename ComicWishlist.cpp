#include "./ComicWishlist.h"

void ComicWishlist::addToWishlist(int id, Comic &comic) {
    wishlist[wishlist.size()+1] = dynamic_cast<Item*>(&comic);
    priceToBePaid += comic.getPrice();
}

void ComicWishlist::printWishlist() {
    std::cout << "\nThe Wishlist, with a total price of" << priceToBePaid << ": \n";
    for(auto i : wishlist){
        std::cout << "ID: " << i.first << ' ';
        std::cout << dynamic_cast<Comic*>(i.second);
        std::cout << '\n';
    }
}
#include "./ComicWishlist.h"

//the addToWishlist function with the Comic parameter, the Wishlist class has a virtual addToWishlist 
//function that takes an Item parameter, so with this, the ComicWishlist can be used in many ways
void ComicWishlist::addToWishlist(int id, Comic &comic) {
    Comic* comicToAdd = new Comic(comic);
    wishlist[wishlist.size()+1] = dynamic_cast<Item*>(comicToAdd);
    std::cout << dynamic_cast<Item*>(&comic)->getItemName() << '\n';
    conditions.push_back(comic.getCondition());
    priceToBePaid += comic.getPrice();
}

//the printwishlist function uses dynamic_cast to print the Comic objects
void ComicWishlist::printWishlist() {
    std::cout << "\nThe Wishlist, with a total price of: " << priceToBePaid << ": \n";
    for(auto i : wishlist){
        std::cout << "ID: " << i.first << ' ';
        std::cout << i.second->getItemName() << ", ";
        std::cout << conditions[i.first-1];
        
        std::cout << '\n';
    }
}

ComicWishlist::~ComicWishlist() {
    for(auto i : wishlist){
        delete i.second;
    }
}
#ifndef POO_WISHLIST_H
#define POO_WISHLIST_H
#include "./Item.h"
#include <map>
#include <memory>
#include <algorithm>
class Wishlist{
protected:
    //wishlist of items and the total price to be paid
    std::map<int, std::shared_ptr<Item>> wishlist;
    int priceToBePaid = 0;
public:
    template <class T>
    //virtual functions that can be used in the derived classes, but also customized
    void addToWishlist(int id, std::shared_ptr<T> item){
        wishlist[wishlist.size()+1] = std::dynamic_pointer_cast<Item>(item);
        priceToBePaid += item->getPrice();
    };
    void removeFromWishlist(int id);
    void printWishlist();

    //bool function to check if the wishlist is empty
    bool isWishListEmpty();

    //basic getters
    int getSize();
    int getPrice();

    //virtual destructor in case the derived classes need to delete something
    //TODO: allocate the wishlist dynamically
    //virtual ~Wishlist(){};
    
    //we need access from the MainInterface, but also from the User class
    friend class User;
    friend class MainInterface;
};

#endif
#ifndef POO_WISHLIST_H
#define POO_WISHLIST_H
#include "./Item.h"
#include <map>

class Wishlist{
protected:
    //wishlist of items and the total price to be paid
    std::map<int, Item*> wishlist;
    int priceToBePaid;
public:
    //virtual functions that can be used in the derived classes, but also customized
    virtual void addToWishlist(int id, Item *item);
    virtual void removeFromWishlist(int id);
    virtual void printWishlist();

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
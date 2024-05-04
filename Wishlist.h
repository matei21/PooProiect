#ifndef POO_WISHLIST_H
#define POO_WISHLIST_H
#include "./Item.h"
#include <map>
class Wishlist{
protected:
    std::map<int, Item*> wishlist;
    int priceToBePaid;
public:
    virtual void addToWishlist(int id, Item *item);
    virtual void removeFromWishlist(int id);
    virtual void printWishlist();
    bool isWishListEmpty();
    int getSize();
    int getPrice();
    virtual ~Wishlist(){};
    friend class User;
    friend class MainInterface;
};

#endif
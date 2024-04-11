#ifndef POO_WISHLIST_H
#define POO_WISHLIST_H
#include "./Comic.h"
#include <map>
class Wishlist{
private:
    std::map<int, Comic> wishlist;
    int priceToBePaid;
public:
    void addToWishlist(int id, Comic &comic);
    void removeFromWishlist(int id);
    void printWishlist();
    bool isWishListEmpty();
    int getSize();
    int getPrice();
    friend class User;
};

#endif
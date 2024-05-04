#ifndef POO_COMIC_WISHLIST_H
#define POO_COMIC_WISHLIST_H
#include "./Comic.h"
#include "./Wishlist.h"
#include <iostream>

class ComicWishlist : public Wishlist{
    void addToWishlist(int id, Comic &comic);
    void printWishlist() override;
    friend class User;
    friend class MainInterface;
};

#endif
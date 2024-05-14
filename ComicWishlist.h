#ifndef POO_COMIC_WISHLIST_H
#define POO_COMIC_WISHLIST_H
#include "./Comic.h"
#include "./Wishlist.h"
#include <iostream>
#include <vector>

//the ComicWishlist inherits from the basic Wishlist, overrides the printWishlist and uses polymorphism
//to add Comic objects while also being able to add Items
class ComicWishlist : public Wishlist{
    private:
        std::vector<std::string> conditions;
    public:
        void addToWishlist(int id, Comic &comic);
        void printWishlist() override;

        //friend classes
        friend class User;
        friend class MainInterface;
        ~ComicWishlist();
};

#endif
#ifndef POO_COMIC_H
#define POO_COMIC_H
#include "./Item.h"
#include <string>
#include <cstring>
class Comic : public Item{
private:
    //std::string comicName;
    //long int comicPrice;
    std::string condition;
    //std::string storeBelong;
    //The store must have full access to the Comic
    friend class Store;

public:
    Comic();
    Comic(char* name_, int price_=0, std::string condition="Fine");
    Comic(const Comic& other);
    void setStoreName(char* nameToSet);
    std::string getStoreBelongName();
    Comic& operator=(Comic& other);
    friend std::ostream& operator<<(std::ostream& os, const Comic& com);
    //~Comic(){};
};

#endif
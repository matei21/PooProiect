#ifndef POO_COMIC_H
#define POO_COMIC_H
#include "./Item.h"
#include <string>
#include <cstring>
class Comic : public Item{
private:
    std::string condition;
    //the store must have full access to the Comic
    friend class Store;

public:
    Comic();
    Comic(char* name_, int price_=0, std::string condition="Fine");

    //copy constructor
    Comic(const Comic& other);

    //getter and setters
    void setStoreName(char* nameToSet);
    std::string getStoreBelongName();
    std::string getCondition();
    
    //operator=
    Comic& operator=(Comic& other);

    //operator<<
    friend std::ostream& operator<<(std::ostream& os, const Comic& com);
    
    //we don't need to free memory because the Item class already does that
    ~Comic(){};
};

#endif
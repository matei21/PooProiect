#ifndef POO_ITEM_H
#define POO_ITEM_H
#include "./ItemInterface.h"
#include <string>
class Item : public ItemInterface{
protected:
    //The 3 main variables that define a comic / update: apparently there was one more
    char* itemName;
    long int itemPrice;
    char* storeBelong;
    //The store must have full access to the Comic
    friend class Store;

public:
    Item();
    Item(char* name_, int price_=0);
    Item(const Item& other);  
    virtual void setStoreName(char* nameToSet) = 0;
    virtual std::string getStoreBelongName() = 0;
    int getPrice() const;
    char* getItemName();
    void printItem();
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    Item& operator=(const Item& other);
    virtual ~Item();
};

#endif
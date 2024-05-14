#ifndef POO_ITEM_H
#define POO_ITEM_H
#include "./ItemInterface.h"
#include <string>
class Item : public ItemInterface{
protected:
    //the 3 main variables that define an item
    char* itemName;
    long int itemPrice;
    char* storeBelong;

    //the store must have full access to the Comic
    friend class Store;

public:
    //basic constructors
    Item();
    Item(char* name_, int price_=0);

    //copy constructor
    Item(const Item& other);

    //pure virtual functions which need to be implemented in the derived classes  
    virtual void setStoreName(char* nameToSet) = 0;
    virtual std::string getStoreBelongName() = 0;

    //basic getters
    int getPrice() const;
    char* getItemName();

    //basic print
    void printItem();

    //operator<< overload
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    
    //operator=
    Item& operator=(const Item& other);
    
    //destructor which is virtual because we want to free the dynamically allocated memory
    //but we also want to be able to call the destructor of the derived classes
    virtual ~Item();
};

#endif
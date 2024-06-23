#ifndef POO_ITEMINTERFACE_H
#define POO_ITEMINTERFACE_H
#include <string>
//we define the interface for the Item class 
//because we want the abstract Item class to have a common interface
class ItemInterface{
public:
    virtual std::string getItemName() = 0;
    virtual int getPrice() const = 0; 
};

#endif
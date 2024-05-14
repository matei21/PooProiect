#ifndef POO_ITEMINTERFACE_H
#define POO_ITEMINTERFACE_H

//we define the interface for the Item class 
//because we want the abstract Item class to have a common interface
class ItemInterface{
public:
    virtual char* getItemName() = 0;
    virtual int getPrice() const = 0; 
};

#endif
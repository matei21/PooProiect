#ifndef POO_ITEMINTERFACE_H
#define POO_ITEMINTERFACE_H

class ItemInterface{
public:
    virtual char* getItemName() = 0;
    virtual int getPrice() const = 0; 
};

#endif
#ifndef POO_STORE_H
#define POO_STORE_H
#include <string>
#include <vector>
#include <map>
#include "./Comic.h"

class Store{
protected:
    std::string storeName;
    std::vector<Item*> allProducts;
public:
    Store(std::string filename);

    //copy constructor
    //Store(Store& other);

    //pure virtual getter for the store name
    virtual std::string getStoreName() = 0;

    //pure virtual function that requires the derived classes to implement the search for a certain item
    virtual std::vector<Comic> findItem(std::string name, int maxSum, std::vector<std::string> params) = 0;

    //operator<<  
    friend std::ostream& operator<<(std::ostream& os, Store& st);
    
    //we don't want to allow the assignment operator
    Store& operator=(Store& other) = delete;

    //destructor
    virtual ~Store(){};
};

#endif
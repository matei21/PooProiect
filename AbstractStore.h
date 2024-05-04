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
    //Store(Store& other);
    virtual std::string getStoreName() = 0;
    
    virtual std::vector<Comic> findItem(std::string name, int maxSum, std::vector<std::string> params) = 0;
    friend std::ostream& operator<<(std::ostream& os, Store& st);
    //Store& operator=(Store& other);
    virtual ~Store(){};
};

#endif
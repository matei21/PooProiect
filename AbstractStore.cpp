#include "./AbstractStore.h"
#include <iostream>
#include <fstream>

//(abstract) Store constructor
Store::Store(std::string name){ 
    this->storeName = name;
}


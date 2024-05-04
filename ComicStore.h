#ifndef POO_COMICSTORE_H
#define POO_COMICSTORE_H
#include <string>
#include <vector>
#include <map>
#include "./Comic.h"
#include "./AbstractStore.h"
class ComicStore : public Store{
private:
    //lists of comics - the availableComics
    //will be generated from allComics with a function call
    //inside the constructor
    //update: that system was thrown away, the condition of the comics
    //is way more important to the collector, if the comic wasn't available
    //, there wouldn't be a need to show the comic, because the purpose of "out of stock"
    //listings is non-existent, in my opinion
    std::map<std::string, std::vector<Comic>> allComics;
    std::map<std::string, std::vector<Comic>> fairComics;
    std::map<std::string, std::vector<Comic>> goodComics;
    std::map<std::string, std::vector<Comic>> veryGoodComics;
    std::map<std::string, std::vector<Comic>> fineComics;
    std::map<std::string, std::vector<Comic>> veryFineComics;
    std::map<std::string, std::vector<Comic>> nearMintComics;
public:
    //Constructor overload - we can initialize a store
    //if we know all its comics or if we have a
    //"database" file
    //update: only the database file initialization is relevant, the comic list is
    //impractical for the purpose of this program
    ComicStore(std::string filename);
    std::string getStoreName(){return this->storeName;}
    //function that allows (the dev, mainly) for the
    //testing of the database functionality
    //update: getAllComics() was unnecesary, findComic is one of the most important
    //functions and the operator is highly useful
    
    std::vector<Comic> findItem(std::string comicName, int maxSum, std::vector<std::string> params);
    friend std::ostream& operator<<(std::ostream& os, const ComicStore& st);
};

#endif
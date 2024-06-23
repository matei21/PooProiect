#ifndef POO_COMICSTORE_H
#define POO_COMICSTORE_H
#include <string>
#include <vector>
#include <map>
#include "./Comic.h"
#include "./AbstractStore.h"
class ComicStore : public Store{
private:
    //maps for each condition so the search is easier and faster
    std::map<std::string, std::vector<Comic>> allComics;
    std::map<std::string, std::vector<Comic>> fairComics;
    std::map<std::string, std::vector<Comic>> goodComics;
    std::map<std::string, std::vector<Comic>> veryGoodComics;
    std::map<std::string, std::vector<Comic>> fineComics;
    std::map<std::string, std::vector<Comic>> veryFineComics;
    std::map<std::string, std::vector<Comic>> nearMintComics;
public:
    //basic constructor
    ComicStore(std::string filename);
    
    //basic getter
    std::string getStoreName(){return this->storeName;}
    
    //the findItem uses the params to search for the comics
    //TODO>: implement the search for items and use more casts for generalization
    std::vector<std::shared_ptr<Item>> find(std::string comicName, int maxSum, std::vector<std::string> params) override;

    //operator<<
    friend std::ostream& operator<<(std::ostream& os, const ComicStore& st);
};

#endif
#ifndef POO_COMIC_H
#define POO_COMIC_H
#include <string>
class Comic{
private:
    //The 3 main variables that define a comic / update: apparently there was one more
    
    std::string comicName;
    long int comicPrice;
    std::string condition;
    std::string storeBelong;
    //The store must have full access to the Comic
    friend class Store;

public:
    Comic();
    Comic(std::string name_, int price_=0, std::string condition="Fine");
    void setStoreName(std::string nameToSet);
    long int getComicPrice() const;
    std::string getStoreBelongName(){return storeBelong;};
    friend std::ostream& operator<<(std::ostream& os, const Comic& com);
};

#endif
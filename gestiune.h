//
// Created by Matei on 3/15/2024.
//
#ifndef POO_GESTIUNE_H
#define POO_GESTIUNE_H
#include <vector>
#include <string>
#include <map>

//COMIC CLASS
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
//END OF COMIC CLASS

//STORE CLASS
class Store{
private:
    //lists of comics - the availableComics
    //will be generated from allComics with a function call
    //inside the constructor
    //update: that system was thrown away, the condition of the comics
    //is way more important to the collector, if the comic wasn't available
    //, there wouldn't be a need to show the comic, because the purpose of "out of stock"
    //listings is non-existent, in my opinion
    
    std::string storeName;
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
    Store(std::string filename);
    std::string getStoreName(){return this->storeName;}
    //function that allows (the dev, mainly) for the
    //testing of the database functionality
    //update: getAllComics() was unnecesary, findComic is one of the most important
    //functions and the operator is highly useful
    
    std::vector<Comic> findComic(std::string comicName, int maxSum, std::string desiredCondition);
    friend std::ostream& operator<<(std::ostream& os, const Store& st);
};

//USER CLASS
class User{
private:
    //Basic user-password combination
    //update: the wishlist is also one of the most important features of the db now
    
    std::map<int, Comic> wishlist;
    int priceToBePaid;
    std::string username;
    std::string password;
public: 
    //Possibly useful in the future?
    //update: yes, one of the good predictions. These getters are used in the 
    //authentication program in order to interrogate the users map of the db
    User(std::string user_, std::string pass_);
    std::string getPassword();
    std::string getUsername();
    //all the Wishlist functions
    void addToWishlist(int id, Comic &comic);
    void removeFromWishlist(int id);
    void printWishlist();
    bool isWishListEmpty();
    friend std::ostream& operator<<(std::ostream& os, User &u1); 
};
//END OF STORE CLASS

//DATABASE CLASS
class Database{
private:
    //Vectors of user-password pairs and the list of
    //stores inside the database, so we know what to display
    
    std::map<std::string, std::string> validUsers;
    std::map<std::string, Store> stores;
public:
    Database(std::string folderName, std::string user_, std::string pass_);
    //function that verifies if the user parameter is valid in the context of the 
    //database object
    bool isValid(User &u1);
    void printDatabase();
    std::map<std::string, Store> getStores(){return stores;}

    //the most important function, the comic finder of the database
    //it takes into account the name of the comic, the budget and the minimum
    //condition that the user wants the comic to be in
    std::map<int,Comic> findComics(std::string desiredName, int maxSum, std::string desiredCondition);
    
};



#endif //POO_GESTIUNE_H

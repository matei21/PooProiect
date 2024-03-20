//
// Created by Matei on 3/15/2024.
//
#ifndef POO_GESTIUNE_H
#define POO_GESTIUNE_H
#include <vector>
#include <string>

//COMIC CLASS
class Comic{
private:
    //The 3 main variables that define a comic
    std::string comicName;
    long int comicPrice;
    bool available;
    //(Maybe) useful functions?
    std::string getComicName() const;
    long int getComicPrice() const;
    bool getAvailability() const;
    //The store must have full access to the Comic
    friend class Store;

public:
    //The constructor must be used by the user
    //and the implementation of the << operator
    Comic(std::string name_, int price_=0, bool availability_=true);
    friend std::ostream& operator<<(std::ostream& os, const Comic& com);
};

//STORE CLASS
class Store{
private:
    //lists of comics - the availableComics
    //will be generated from allComics with a function call
    //inside the constructor
    std::vector<Comic> allComics;
    std::vector<Comic> availableComics;
public:
    //Constructor overload - we can initialize a store
    //if we know all its comics or if we have a
    //"database" file
    Store(std::vector<Comic> list_);
    Store(std::string filename);
    //function that allows (the dev, mainly) for the
    //testing of the database functionality
    std::vector<Comic> getAllComics() const;
    std::vector<Comic> getAvailableComics() const;
};

//DATABASE CLASS
class Database{
private:
    //Vectors of user-password pairs and the list of
    //stores inside the database, so we know what to display
    std::vector<std::pair<std::string, std::string>> validUsers;
    std::vector<Store> stores;
public:
    //Basic contructor - NOT YET IMPLEMENTED
    Database();
};

//USER CLASS
class User{
private:
    //Basic user-password combination
    std::string username;
    std::string password;
public:
    //Possibly useful in the future?
    std::string getPassword();
};

#endif //POO_GESTIUNE_H

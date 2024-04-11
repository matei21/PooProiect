#ifndef POO_DATABASE_H
#define POO_DATABASE_H
#include "./Store.h"
#include "./User.h"

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
#endif
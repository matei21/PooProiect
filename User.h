#ifndef POO_USER_H
#define POO_USER_H
#include "./Wishlist.h"

class User{
private:
    static int userCount;
    
    //class composition, each user has a wishlist
    Wishlist userwishlist;
    
    //the 2 main variables that define a user
    std::string username;
    std::string password;
public: 
    //static getter for the static variable
    static int getUserCount();

    //basic constructor  
    User(std::string user_, std::string pass_);

    //basic getters
    std::string getPassword();
    std::string getUsername();

    //operator<< overload
    friend std::ostream& operator<<(std::ostream& os, User &u1); 

    //we need access from the MainInterface
    friend class MainInterface;
};
#endif
#ifndef POO_USER_H
#define POO_USER_H
#include "./Wishlist.h"
class User{
private:
    Wishlist userwishlist;
    //Basic user-password combination
    //update: the wishlist is also one of the most important features of the db now
    std::string username;
    std::string password;
public: 
    //Possibly useful in the future?
    //update: yes, one of the good predictions. These getters are used in the 
    //authentication program in order to interrogate the users map of the db
    User(std::string user_, std::string pass_);
    std::string getPassword();
    std::string getUsername();
    friend std::ostream& operator<<(std::ostream& os, User &u1); 
    friend class MainInterface;
};
#endif
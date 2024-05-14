#include "./User.h"
#include <iostream>

//the userCount is static and it's used to keep track of the number of users (it could be used later for many reasons)
int User::userCount = 0;

//basic constructor
User::User(std::string user_, std::string pass_){
    this->username = user_;
    this->password = pass_;
    userCount++;
}

//basic getters
int User::getUserCount(){
    return userCount;
}

std::string User::getUsername(){
    return this->username;
}

std::string User::getPassword(){
    return this->password;
}


//operator<<
std::ostream& operator<<(std::ostream& os, User &u1){
    os << u1.username << ", you have " << u1.userwishlist.getSize() << " comics in your wishlist, totalling " << u1.userwishlist.getPrice() << " RON. ";
    return os;
}
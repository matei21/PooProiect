#include "./User.h"
#include <iostream>

int User::userCount = 0;
User::User(std::string user_, std::string pass_){
    this->username = user_;
    this->password = pass_;
    userCount++;
}

int User::getUserCount(){
    return userCount;
}

std::string User::getUsername(){
    return this->username;
}

std::string User::getPassword(){
    return this->password;
}

std::ostream& operator<<(std::ostream& os, User &u1){
    os << u1.username << ", you have " << u1.userwishlist.getSize() << "comics in your wishlist, totalling " << u1.userwishlist.getPrice() << "RON. ";
    return os;
}
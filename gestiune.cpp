//
// Created by Matei on 3/15/2024.
//
#include <cstring>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "gestiune.h"

//COMIC
Comic::Comic(){

}
Comic::Comic(std::string name_, int price_, std::string condition) {
    this->comicName = name_;
    this->comicPrice = price_;
    this->condition = condition;
}

std::string Comic::getComicName() const {
    std::string comicNameDouble = comicName;
    return comicNameDouble;
}
long int Comic::getComicPrice() const {
    long int comicPriceDouble = comicPrice;
    return comicPriceDouble;
}

void Comic::setStoreName(std::string nameToSet) {
    this->storeBelong = nameToSet;
}

std::ostream& operator<<(std::ostream& os, const Comic& com){
    os << "Name:" << com.comicName << ", " <<
       com.comicPrice << " lei in the condition of: " << com.condition << '\n';
    return os;
}

//END OF COMIC


//STORE
Store::Store(std::string filename){
    //We open the file
    std::ifstream file;
    file.open(filename);
    if(file.fail()){
        std::cerr << strerror(errno);
    }
    std::vector<std::string> vec;
    std::string line, name;
    std::getline(file, name);
    this->storeName = name;
    while(!file.eof()){
        std::getline(file, line);
        vec.push_back(line);

        //When we reach another set of 3 values
        //that define the Comic, we add the Comic to the Store list
        if(vec.size()%3==0){
            std::string condition = vec[vec.size()-1];
            Comic c1 = Comic(vec[vec.size()-3],
                             std::atoi(vec[vec.size()-2].c_str()),
                             condition);
            allComics.insert({c1.comicName,{c1}});
            if(condition == "Fair"){fairComics[c1.comicName].push_back(c1);}
            if(condition == "Good"){goodComics[c1.comicName].push_back(c1);}
            if(condition == "Very Good"){veryGoodComics[c1.comicName].push_back(c1);}
            if(condition == "Fine"){fineComics[c1.comicName].push_back(c1);}
            if(condition == "Very Fine"){veryFineComics[c1.comicName].push_back(c1);}
            if(condition == "Near Mint"){nearMintComics[c1.comicName].push_back(c1);}
        }

    }
}


int transform(std::string condition){
    if(condition == "Poor"){return 0;}
    if(condition == "Fair"){return 1;}
    if(condition == "Good"){return 2;}
    if(condition == "Very Good"){return 3;}
    if(condition == "Fine"){return 4;}
    if(condition == "Very Fine"){return 5;}
    if(condition == "Near Mint"){return 6;}
    return 0;
}

std::vector<Comic> Store::findComic(std::string comicName, int maxSum, std::string desiredCondition) {
    switch (transform(desiredCondition)) {
        case 6: 
            return nearMintComics[comicName];
        case 5:{  
            std::vector<Comic> result = nearMintComics[comicName];
            for(auto i: veryFineComics[comicName]){result.push_back(i);}
            return result;
        }
        case 4:{  
            std::vector<Comic> result = nearMintComics[comicName];
            for(auto i: veryFineComics[comicName]){result.push_back(i);}
            for(auto i: fineComics[comicName]){result.push_back(i);}
            return result;
        }
        case 3:{  
            std::vector<Comic> result = nearMintComics[comicName];
            for(auto i: veryFineComics[comicName]){result.push_back(i);}
            for(auto i: fineComics[comicName]){result.push_back(i);}
            for(auto i: veryGoodComics[comicName]){result.push_back(i);}
            return result;
        }
        case 2:{ 
            std::vector<Comic> result = nearMintComics[comicName];
            for(auto i: veryFineComics[comicName]){result.push_back(i);}
            for(auto i: fineComics[comicName]){result.push_back(i);}
            for(auto i: veryGoodComics[comicName]){result.push_back(i);}
            for(auto i: goodComics[comicName]){result.push_back(i);}
            return result;
        }
        case 1:{ 
            std::vector<Comic> result = nearMintComics[comicName];
            for(auto i: veryFineComics[comicName]){result.push_back(i);}
            for(auto i: fineComics[comicName]){result.push_back(i);}
            for(auto i: veryGoodComics[comicName]){result.push_back(i);}
            for(auto i: goodComics[comicName]){result.push_back(i);}
            for(auto i: fairComics[comicName]){result.push_back(i);}
            return result;
        }
        case 0:{ 
            return allComics[comicName]; 
        }     
    }
    return allComics[comicName];
}

std::ostream& operator<<(std::ostream& os, const Store& st){
    for(auto i : st.allComics){
        std::cout << "The comic ";
        std::cout << i.first;
        std::cout << "is available in the following forms: ";
        for(auto j : i.second){
            std::cout << j;
        }
    }
    return os;
}
//END OF STORE

//USER CLASS

User::User(std::string user_, std::string pass_){
    this->username = user_;
    this->password = pass_;
}

std::string User::getUsername(){
    return this->username;
}

std::string User::getPassword(){
    return this->password;
}

bool Database::isValid(User &u1){
    return validUsers[u1.getUsername()] == u1.getPassword();
}

void User::addToWishlist(int id, Comic &comic) {
    wishlist.insert({wishlist.size()+1, comic});
    priceToBePaid += comic.getComicPrice();
}

void User::removeFromWishlist(int id) {
    wishlist.erase(id);
}

void User::printWishlist() {
    for(auto i : wishlist){
        std::cout << "ID: " << i.first;
        std::cout << i.second;
        std::cout << '\n';
    }
}

bool User::isWishListEmpty(){
    return wishlist.size() == 0;
}

//DATABASE CLASS
Database::Database(std::string folderName, std::string user_,
                   std::string pass_){
    //database loading
    for(const auto &entry : std::filesystem::directory_iterator(folderName)){
        if(entry.path()!="bd/USERS.txt"){
            Store storeToInsert = Store(entry.path());
            stores.insert({storeToInsert.getStoreName(),storeToInsert});
        }
        else{
            int size = 0;
            std::ifstream readFromUsers("bd/USERS.txt");
            std::string line;
            while(std::getline(readFromUsers, line)){
                auto firstSpace = line.find(' ');
                std::string user = line.substr(0, firstSpace);
                std::string password = line.substr(firstSpace+1, std::string::npos);
                validUsers.insert({user, password});
            }
        }
    }
}

std::map<int, Comic> Database::findComics(std::string desiredName, int maxSum, std::string desiredCondition) {
    std::map<int, Comic> bigResult;
    int id = 1;
    for(auto i : stores){
        auto result = i.second.findComic(desiredName, maxSum, desiredCondition);
        if(result.size()){
            for(auto j : result){
                j.setStoreName(i.first);
                bigResult.insert({id, j});
                id++;
            }
        }
        else{
            
        }
    }
    return bigResult;
}

void Database::printDatabase(){
    std::cout << "The stores and comics: " << std::endl;
    for(auto i : stores){
        std::cout << "Store name: " << i.first  << i.second << '\n';
    }
}
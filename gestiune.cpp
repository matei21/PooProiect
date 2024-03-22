//
// Created by Matei on 3/15/2024.
//
#include <cstring>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "gestiune.h"

//COMIC
Comic::Comic(std::string name_, int price_, bool availability_) {
    this->comicName = name_;
    this->comicPrice = price_;
    this->available = availability_;
}

std::string Comic::getComicName() const {
    std::string comicNameDouble = comicName;
    return comicNameDouble;
}
long int Comic::getComicPrice() const {
    long int comicPriceDouble = comicPrice;
    return comicPriceDouble;
}
bool Comic::getAvailability() const {
    return this->available;
}

std::ostream& operator<<(std::ostream& os, const Comic& com){
    os << "Nume:" << com.comicName << ' ' <<
    com.comicPrice << " lei si este disponibila: " << com.available << '\n';
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
    std::string line;
    bool eof = false;
    while(!file.eof()){
        //we add each line to the result vector
        //it's possible to optimise this further? TODO
        std::getline(file, line);
        vec.push_back(line);
        
        //When we reach another set of 3 values
        //that define the Comic, we add the Comic to the Store list
        if(vec.size()%3==0){
            bool toInsert;
            if(strcmp(vec[vec.size()-1].c_str(),"available")==0){
                toInsert = true;
            } else{
                toInsert= false;
            }
            Comic c1 = Comic(vec[vec.size()-3],
                             std::atoi(vec[vec.size()-2].c_str()),
                             toInsert);
            allComics.push_back(c1);
        }

    }
}

Store::Store(std::vector<Comic> list_) {
    for(auto i : list_){
        this->allComics.push_back(i);
        if(i.getAvailability()){
            this->availableComics.push_back(i);
        }
    }
}

std::vector<Comic> Store::getAllComics() const{
    std::vector<Comic> result;
    for(auto i : this->allComics){
        result.push_back(i);
    }
    return result;
}
std::vector<Comic> Store::getAvailableComics() const {
    std::vector<Comic> result;
    for(auto i : this->availableComics){
        result.push_back(i);
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Store& st){
    for(auto i : st.allComics){
        std::cout << i;
    }
    return os;
}

//DATABASE CLASS
Database::Database(std::string folderName, std::string user_, std::string pass_){
    //database loading
    for(const auto &entry : std::filesystem::directory_iterator(folderName)){
        if(entry.path()!="bd/USERS.txt"){
            Store storeToInsert(entry.path());
            stores.push_back(storeToInsert);
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

void Database::printDatabase(){
    std::cout << "The users: " << std::endl;
    for(auto i : validUsers){
        std::cout << i.first << ' ' << i.second << std::endl;
    }
    std::cout << "The stores and comics: " << std::endl;
    for(auto i : stores){
        std::cout << i << '\n';
    }
}
//END OF STORE


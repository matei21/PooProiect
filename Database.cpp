#include "./Database.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstring>
#include "InvalidUser.h"
Database::Database(std::string folderName, std::string user_,
                   std::string pass_){
    //database loading
    for(const auto &entry : std::filesystem::directory_iterator(folderName)){
        if(entry.path()!="bd/USERS.txt"){
            ComicStore storeToInsert = ComicStore(entry.path());
            stores.insert({storeToInsert.getStoreName(),std::move(storeToInsert)});
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
//lib curl, wget TODO
std::map<int, std::shared_ptr<Item>> Database::findComics(std::string desiredName, int maxSum, std::string desiredCondition) {
    std::map<int, std::shared_ptr<Item>> bigResult;
    int id = 1;
    for(auto i : stores){
        std::vector<std::string> params;
        params.push_back(desiredCondition); 
        auto result = i.second.find(desiredName, maxSum, params);
        if(result.size()){
            for(auto j : result){
                char* toSet = new char[i.first.size()];
                strcpy(toSet, i.first.c_str());
                std::dynamic_pointer_cast<Comic>(j)->setStoreName(toSet);
                bigResult[id] = j;
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

bool Database::isValid(User &u1){
    if(validUsers[u1.getUsername()] == u1.getPassword()){
        return true;
    }
    else{
        throw InvalidUser();
        return false;
    }
}
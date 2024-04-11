#include "./Database.h"
#include <filesystem>
#include <fstream>
#include <iostream>
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
//lib curl, wget TODO
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

bool Database::isValid(User &u1){
    return validUsers[u1.getUsername()] == u1.getPassword();
}
#include "./ComicStore.h"
#include <fstream>
#include <iostream>
#include <cerrno>
#include <vector>
#include <cstring>

ComicStore::ComicStore(std::string filename) : Store(filename){
    //We open the file
    std::ifstream file;
    file.open(filename);
    if(file.fail()){
        std::cout << "File open failed.";
        return;
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
            char* c1name = new char[vec[vec.size()-3].size()];
            strcpy(c1name, vec[vec.size()-3].c_str());
            Comic c1 = Comic(c1name,
                             std::atoi(vec[vec.size()-2].c_str()),
                             condition);
            //char* c1name = dynamic_cast<Item*>(&c1)->getItemName();
            allComics.insert({c1name,{c1}});
            if(condition == "Fair"){fairComics[c1name].push_back(c1);}
            if(condition == "Good"){goodComics[c1name].push_back(c1);}
            if(condition == "Very Good"){veryGoodComics[c1name].push_back(c1);}
            if(condition == "Fine"){fineComics[c1name].push_back(c1);}
            if(condition == "Very Fine"){veryFineComics[c1name].push_back(c1);}
            if(condition == "Near Mint"){nearMintComics[c1name].push_back(c1);}
        }
    //strtol documentat
    }
    file.close();
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
std::vector<Comic> ComicStore::findItem(std::string comicName, int maxSum, std::vector<std::string> params){
    std::string desiredCondition = params[0];
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

std::ostream& operator<<(std::ostream& os, const ComicStore& st){
    for(auto i : st.allComics){
        std::cout << "The comic ";
        std::cout << i.first;
        std::cout << " is available in the following forms: ";
        for(auto j : i.second){
            std::cout << j;
        }
    }
    return os;
}
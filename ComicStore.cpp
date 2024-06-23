#include "./ComicStore.h"
#include <fstream>
#include <iostream>
#include <cerrno>
#include <vector>
#include <cstring>

//basic constructor which also initializes the Store class
ComicStore::ComicStore(std::string filename) : Store(filename){
    //We open the file
    std::ifstream file;
    file.open(filename);
    if(file.fail()){
        std::cout << "File open failed.";
        return;
    }

    //setting the store name
    std::vector<std::string> vec;
    std::string line, name;
    std::getline(file, name);
    this->storeName = name;

    //we start to read the file for Comics
    while(!file.eof()){
        std::getline(file, line);
        vec.push_back(line);

        //when we reach another set of 3 values
        //that define the Comic, we add the Comic to the Store list
        if(vec.size()%3==0){
            std::string condition = vec[vec.size()-1];
            char* c1name = new char[vec[vec.size()-3].size()];
            strcpy(c1name, vec[vec.size()-3].c_str());

            //we create the Comic object
            Comic c1 = Comic(c1name,
                             std::atoi(vec[vec.size()-2].c_str()),
                             condition);

            //here we add the Comic where it belongs
            allComics.insert({c1name,{c1}});
            if(condition == "Fair"){fairComics[c1name].push_back(c1);}
            if(condition == "Good"){goodComics[c1name].push_back(c1);}
            if(condition == "Very Good"){veryGoodComics[c1name].push_back(c1);}
            if(condition == "Fine"){fineComics[c1name].push_back(c1);}
            if(condition == "Very Fine"){veryFineComics[c1name].push_back(c1);}
            if(condition == "Near Mint"){nearMintComics[c1name].push_back(c1);}
        }
    }
    file.close();
}

//funtion that transforms the string condition into an int so it's easier to compare
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

//findItem function that returns the Comics that match the desired condition
std::vector<std::shared_ptr<Item>> ComicStore::find(std::string comicName, int maxSum, std::vector<std::string> params){
    std::string desiredCondition = params[0];
    switch (transform(desiredCondition)) {
        //for each condition which is now a case, we create results that will look at the right maps
        case 6:{ 
            std::vector<std::shared_ptr<Item>> result;
            for(auto i: nearMintComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result;
        }
        case 5:{  
            std::vector<std::shared_ptr<Item>> result; 
            for(auto i: veryFineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result;
        }
        case 4:{  
            std::vector<std::shared_ptr<Item>> result;
            for(auto i: veryFineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: fineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result;
        }
        case 3:{  
            std::vector<std::shared_ptr<Item>> result;
            for(auto i: veryFineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: fineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: veryGoodComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result;
        }
        case 2:{ 
            std::vector<std::shared_ptr<Item>> result;
            for(auto i: veryFineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: fineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: veryGoodComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: goodComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result;
        }
        case 1:{ 
            std::vector<std::shared_ptr<Item>> result;
            for(auto i: veryFineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: fineComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: veryGoodComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: goodComics[comicName]){    
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            for(auto i: fairComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result;
        }
        case 0:{ 
            std::vector<std::shared_ptr<Item>> result;
            for(auto i : allComics[comicName]){
                result.push_back(std::dynamic_pointer_cast<Item>(std::make_shared<Comic>(i)));
            }
            return result; 
        }     
    }
    std::vector<std::shared_ptr<Item>> result;
            for(auto it : allComics){
                for(auto i : it.second){
                    std::shared_ptr<Comic> com = std::make_shared<Comic>(i);
                    result.push_back(std::dynamic_pointer_cast<Item>(com));
                }
            }
    return result; 
}

//basic operator<<
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
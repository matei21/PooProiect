#ifndef POO_INTERFACE_H
#define POO_INTERFACE_H
#include "./AbstractStore.h"
#include "./Comic.h"
#include "./ComicStore.h"
#include "./User.h"
#include "./Database.h"
#include "./ComicWishlist.h"
#include "./Wishlist.h"
#include "./Item.h"
#include "./InvalidUser.h"
#include <iostream>
#include <sstream>
class MainInterface{
public:
    static void run(){
    
    //basic authentication for the user
    std::string usernameFromConsole, passwordFromConsole;
    std::cout << "Credential check: user: ";
    std::cin >> usernameFromConsole;
    std::cout << "password: ";
    std::cin >> passwordFromConsole;

    //we create the DB and User objects
    Database d1("bd", usernameFromConsole, passwordFromConsole);
    User u1(usernameFromConsole, passwordFromConsole);

    //if user is valid, otherwise we throw an exception
    if(d1.isValid(u1)){

        //basic user interface with the database
        //TODO: f, q and others, not only numbers
        char command;
        std::cout << "Welcome! Command list for the database: 1(or f) to lookup a certain comic book (returns the stores where it's available), 2(or s) to show the list of stores, 3(or w) to view your wishlist and 4(or r) to return to this main menu and 0(or q) to exit the program" << std::endl;
        while(command != '0' && command != 'q'){
            std::cout << "\nCommand: ";
            std::cin >> command;
            switch(command) {
                case '1':{

                    //basic search for a comic
                    std::string aaa;
                    std::getline(std::cin, aaa);
                    std::cout << aaa;
                    std::cout
                            << "\nSearch filters: Name, Maximum price and the minimum condition the comic needs to be in (options: Poor, Fair, Good, Very Good, Fine, Very Fine, Near Mint in this order). If you have no preferences, simply insert Poor" << std::endl;
                    
                    std::string desiredName, desiredCondition;
                    int maxSum;
                    std::string userInput;
                    std::cout << "\nName of comic: ";
                    std::getline(std::cin, desiredName);
                    std::cout << "\nMax sum you're willing to pay: ";
                    std::cin >> maxSum;
                    std::cin.ignore();
                    std::cout << "\nMinimum desired condition: ";
                    std::getline(std::cin, desiredCondition);
                    
                    //we get the results using the findComics function and then we display them
                    std::map<int, Comic> results = d1.findComics(desiredName, maxSum, desiredCondition);
                    std::cout << std::endl;
                    for (auto i: results) {
                        std::cout << "Store: " << i.second.getStoreBelongName() << " with the ID: ";
                        std::cout << i.first;
                        std::cout << ' ';
                        std::cout << i.second;
                    }

                    //if no results
                    if(results.size() == 0){
                        std::cout << "No results match your description!\n"; 
                        break;
                    }

                    //interact with the wishlist after this
                    std::cout << "\nDo you wish to add any of these to your wishlist? If so, type the IDs of all the variants which you wish to add: ";
                    std::string input;
                    std::getline(std::cin, input);
                    std::istringstream iss(input);
                    int id;

                    //we read the ids for the comics we want to add to the wishlist
                    while(iss >> id){
                        if(results.find(id) != results.end()){
                            std::cout << "\nThe ID: " << id << " has been added!\n" << std::endl;
                            u1.userwishlist.addToWishlist(id, results[id]);
                        }
                        else{
                            std::cout << "The id " << id << " does not exist, we have added the other IDs\n";
                        }
                    }
                    break;
                }

                //simple DB print
                case '2':{
                    d1.printDatabase();
                    break;
                }

        
                case '3':{

                    //if the wishlist is empty, we print            
                    if(u1.userwishlist.isWishListEmpty()){
                        std::cout << "Your Wishlist is empty! Add some comics to it!\n";
                        break;
                    }

                    //wishlist print 
                    std::cout << u1;
                    u1.userwishlist.printWishlist();

                    //wishlist remove, if needed
                    std::cout << "\nDo you wish to remove any items from your wishlist? If so, write down all the IDs of the comics which you wish to remove\n";
                    std::string input;
                    std::string id;
                    std::cin.ignore();
                    std::getline(std::cin, input);
                    
                    //we read the ids for the comics we want to remove from the wishlist
                    std::stringstream input1(input);
                    while(std::getline(input1, id, ' ')){
                        u1.userwishlist.removeFromWishlist(std::atoi(id.c_str()));
                        std::cout << "Removed id " << id << " from the wishlist!\n";
                    }
                    break;
                }

                //print command list 
                case '4':{
                    std::cout << "\nCommand list for the database: 1(or f) to lookup a certain comic book (returns the stores where it's available), 2(or s) to show the list of stores, 3(or r) to return to this main menu and 0(or q) to exit the program\n";
                    break;
                }

                //program exit
                case '0':{
                    break;
                }
            }
        }

    //if the user is invalid, we throw an exception
    }else{
        try{
            d1.isValid(u1);
        }catch(InvalidUser &e){
            std::cerr << e.what() << std::endl;
        }
     }
    }
};

#endif
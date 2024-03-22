#include "gestiune.h"
#include <iostream>
#include <fstream>
#include <cstring>

int main(){
    //TEST

    //TO-DO: implement a system of "in stock", "out of stock" and "in
    //supplier stock" system where the comic's available state isn't simply
    //true or false and of course implement the database with allowed users
    //and credentials. So far the test for reading and populating stores with
    //comics from files was decent.
    std::string usernameFromConsole, passwordFromConsole;
    std::cout << "Credential check: user: ";
    std::cin >> usernameFromConsole;
    std::cout << "password: ";
    std::cin >> passwordFromConsole;
    Database d1("bd", usernameFromConsole, passwordFromConsole);
    d1.printDatabase();
    
}
#include "gestiune.h"
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;


int main(){
    //TEST

    //TO-DO: implement a system of "in stock", "out of stock" and "in
    //supplier stock" system where the comic's available state isn't simply
    //true or false and of course implement the database with allowed users
    //and credentials. So far the test for reading and populating stores with
    //comics from files was decent.
    Store s1("C:\\Users\\Matei\\ClionProjects\\POO\\store1.txt");
    vector<Comic> all = s1.getAllComics();
    for(auto i : all){
        std::cout << i;
    }
}
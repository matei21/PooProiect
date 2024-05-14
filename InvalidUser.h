#include <stdexcept>

class InvalidUser : public std::exception {
public:
    //basic exception class for error handling of invalid users
    InvalidUser(){};
    const char* what() const noexcept override {
        return "Wrong combination of credentials. Please retry running the program with the correct credentials. Goodbye!";
    }

};
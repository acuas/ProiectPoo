//
// Created by auras on 09.05.2018.
//

#ifndef PROIECT2_EXTENDEXCEPTION_H
#define PROIECT2_EXTENDEXCEPTION_H
#include <exception>

using namespace std;

class bad_sex : public exception {
    public:
        const char * what () const throw() override {
            return "This kind of sex doesn't exist!";
        }
};

class bad_age : public exception {
    public:
        const char * what() const throw() override {
            return "The age is invalid!";
        }
};

class bad_create : public exception {
    public:
        const char * what() const throw() override {
            return "You are trying to create an undefined destination!";
        }
};

#endif //PROIECT2_EXTENDEXCEPTION_H

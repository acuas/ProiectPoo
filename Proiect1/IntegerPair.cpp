//
// Created by auras on 27.03.2018.
// Last modified by auras on 27.03.2018
//

#include "IntegerPair.h"

IntegerPair::IntegerPair(int x, int y) {
    this->x = new int;
    this->y = new int;
    *(this->x) = x;
    *(this->y) = y;
}

IntegerPair::IntegerPair(const IntegerPair &obj) {
    //allocate the memory
    this->x = new int;
    this->y = new int;

    (*this->x) = *obj.x;
    (*this->y) = *obj.y;
}

IntegerPair::~IntegerPair() {
    delete x;
    delete y;
}

istream &operator>>(istream &in, IntegerPair &obj) {
    int aux1, aux2;

    do {
        cout << "First number : ";
        in >> aux1;
        if(aux1 < 0 || aux1 > INF)
            cout << "First number need to be in range [0, " << INF << "]\n";
    }while(aux1 < 0 || aux1 > INF);

    do {
        cout << "Second number : ";
        in >> aux2;
        if(aux2 < 0 || aux2 > INF)
            cout << "Second number need to be in range [0, " << INF << "]\n";
    }while(aux2 < 0 || aux2 > INF);

    *obj.x = aux1;
    *obj.y = aux2;
    return in;
}

IntegerPair &IntegerPair::operator=(const IntegerPair &obj) {
    if(this == &obj)
        return *this;

    //make deep copy of obj
    (*this->x) = *obj.x;
    (*this->y) = *obj.y;

    return *this;
}

bool IntegerPair::operator<(const IntegerPair &obj) const{
    return (*this->x < *obj.x)
           || (*this->x == *obj.x && *this->y < *obj.y);
}

bool IntegerPair::operator>(const IntegerPair &obj) const{
    return (*this->x > *obj.x)
           || (*this->x == *obj.x && *this->y < *obj.y);
}

bool IntegerPair::operator==(const IntegerPair &obj) const{
    return *this->x == *obj.x && *this->y == *obj.y;
}

bool IntegerPair::operator!=(const IntegerPair &obj) const{
    return !(*this->x == *obj.x && *this->y == *obj.y);
}

bool IntegerPair::operator<=(const IntegerPair &obj) const{
    return *this == obj || *this < obj;
}

bool IntegerPair::operator>=(const IntegerPair &obj) const{
    return *this == obj || *this > obj;
}

ostream &operator<<(ostream &out, const IntegerPair &obj) {
    out << '(' << *obj.x << "," << *obj.y << ')';
    return out;
}

IntegerPair make_pair(int x, int y) {
    return IntegerPair(x, y);
}
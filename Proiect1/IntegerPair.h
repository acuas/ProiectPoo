//
// Created by auras on 27.03.2018.
// Last modified by auras on 27.03.2018
//

#ifndef PROIECT1_INTEGERPAIR_H
#define PROIECT1_INTEGERPAIR_H

#include <iostream>
#define INF 10005
using namespace std;

class IntegerPair;

extern IntegerPair make_pair(int x, int y);

class IntegerPair {
    private :
        int *x, *y;
    public :
        explicit IntegerPair(int x = 0, int y = 0);
        IntegerPair(const IntegerPair&);
        ~IntegerPair();
        int &first() {
            return *x;
        }
        int &second() {
            return *y;
        }

        IntegerPair &operator=(const IntegerPair &);
        bool operator<(const IntegerPair &) const;
        bool operator>(const IntegerPair &) const;
        bool operator>=(const IntegerPair &) const;
        bool operator<=(const IntegerPair &) const;
        bool operator==(const IntegerPair &) const;
        bool operator!=(const IntegerPair &) const;

        friend istream &operator>>(istream &, IntegerPair &);
        friend ostream &operator<<(ostream &, const IntegerPair &);
};


#endif //PROIECT1_INTEGERPAIR_H

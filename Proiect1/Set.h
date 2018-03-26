//
// Created by auras on 21.03.2018.
// Last modified by auras on 26.03.2018
//

#ifndef PROIECT1_SET_H
#define PROIECT1_SET_H
#include "LinkedList.h"
#define INF 10000

class Set {
    private:
        LinkedList *A;
    public:
        Set();
        explicit Set(const LinkedList &B);
        ~Set();

        void transform(LinkedList &B);

        Set operator+(const Set &);
        Set operator*(const Set &);
        Set operator-(const Set &);
        Set &operator=(const Set &);

        friend istream &operator>>(istream &, Set &);
        friend ostream &operator<<(ostream &, const Set &);
};

#endif //PROIECT1_SET_H

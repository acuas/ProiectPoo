//
// Created by auras on 21.03.2018.
// Last modified by auras on 27.03.2018
//

#ifndef PROIECT1_SET_H
#define PROIECT1_SET_H
#include "LinkedList.h"

template <class T> class Set;

template <class T>
extern istream &operator>>(istream &, Set<T> &);

template <class T>
extern ostream &operator<<(ostream &, const Set<T> &);

template <class T>
class Set {
    private:
        LinkedList<T> *A;
    public:
        Set();
        explicit Set(const LinkedList<T> &B);
        Set(const Set &);
        ~Set();

        void transform(LinkedList<T> &B);
        void insert(T);

        Set operator+(const Set &);
        Set operator*(const Set &);
        Set operator-(const Set &);
        Set &operator=(const Set &);

        bool operator<(const Set &) const;
        bool operator==(const Set &) const;
        bool operator!=(const Set &) const;

        friend Set<IntegerPair> produs(const Set<int> &, const Set<int> &);
        friend istream &operator>> <T>(istream &, Set<T> &);
        friend ostream &operator<< <T>(ostream &, const Set<T> &);
};

#endif //PROIECT1_SET_H

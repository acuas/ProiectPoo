//
// Created by auras on 21.03.2018.
// Last modified by auras on 27.03.2018
//

#include <iostream>
#include "Set.h"

template class Set<int>;
template class Set<IntegerPair>;

template istream &operator>> <int>(istream &, Set<int> &);
template istream &operator>> <IntegerPair>(istream &, Set<IntegerPair> &);

template ostream &operator<< <int>(ostream &, const Set<int> &);
template ostream &operator<< <IntegerPair>(ostream &, const Set<IntegerPair> &);

template <class T>
Set<T>::Set() {
    A = new LinkedList<T>;
}

template <class T>
Set<T>::Set(const LinkedList<T> &B) {
    A = new LinkedList<T>;
    (*A) = B;
    transform((*A));
}

//Overload copy constructor
template <class T>
Set<T>::Set(const Set<T> &obj) {
    A = new LinkedList<T>;
    (*A) = *obj.A;
}

template <class T>
Set<T>::~Set() {
    delete A;
}

template <class T>
void Set<T>::transform(LinkedList<T> &B) {
    B.sort();
    B.unique();
}

template <class T>
void Set<T>::insert(T __tmp) {
    A->insertFront(__tmp);
    A->sort();
    A->unique();

}

template <class T>
Set<T> Set<T>::operator+(const Set<T> &obj) {
    //declaration
    Set<T> aux;
    Node<T> * i = this->A->begin();
    Node<T> * j = obj.A->begin();

    //Algorithm that use merge idea
    while(i != nullptr && j != nullptr) {
        if(*i == *j) { //ATENTIE: Fara * comparam adresele de aicea era bug-ul
            aux.A->insertAfter(i->getX());
            i = i->getNext();
            j = j->getNext();
        }
        else if(*i < *j) {
            aux.A->insertAfter(i->getX());
            i = i->getNext();
        }
        else if(*j < *i) {
            aux.A->insertAfter(j->getX());
            j = j->getNext();
        }
    }
    while(i != nullptr) {
        aux.A->insertAfter(i->getX());
        i = i->getNext();
    }
    while(j != nullptr) {
        aux.A->insertAfter(j->getX());
        j = j->getNext();
    }

    return aux;
}

template <class T>
Set<T> Set<T>::operator*(const Set<T> &obj) {
    Set<T> aux;
    Node<T> * i = obj.A->begin();
    Node<T> * j = this->A->begin();

    while(i != nullptr && j != nullptr) {
        if(*i == *j) {
            aux.A->insertAfter(i->getX());
            i = i->getNext();
            j = j->getNext();
        }
        else if(*i < *j)
            i = i->getNext();
        else
            j = j->getNext();
    }

    return aux;
}

template <class T>
Set<T> Set<T>::operator-(const Set<T> &obj) {
    Set<T> aux;
    Node<T> * i = obj.A->begin();
    Node<T> * j = this->A->begin();

    while(i != nullptr && j != nullptr) {
        if(*i == *j){
            i = i->getNext();
            j = j->getNext();
        }
        else if(*j < *i) {
            aux.A->insertAfter(j->getX());
            j = j->getNext();
        }
        else {
            i = i->getNext();
        }
    }
    while(j != nullptr){
        aux.A->insertAfter(j->getX());
        j = j->getNext();
    }

    return aux;
}

template <class T>
Set<T> &Set<T>::operator=(const Set<T> &obj) {
    if(this == &obj)
        return *this;

    if(!A->empty())
        A->clear();

    for(Node<T> * cross = obj.A->begin(); cross != nullptr; cross = cross->getNext())
        A->insertAfter(cross->getX());

    return *this;

}

template <class T>
bool Set<T>::operator<(const Set<T> &obj) const {
    return *this->A < *obj.A;
}

template <class T>
bool Set<T>::operator!=(const Set<T> &obj) const {
    return *this->A != *obj.A;
}

template <class T>
bool Set<T>::operator==(const Set<T> &obj) const {
    return *this->A == *obj.A;
}

template <class T>
istream &operator>>(istream &in, Set<T> &obj) {
    long long n;
    do {
        cout << "Number of elements : ";
        in >> n;
        if(n < 0 || n > INF)
            cout << "The number of the elements need to be in range [0, " << INF << "]\n";
    }while(n < 0 || n > INF);

    if(n > 0) {
        T __tmp;
        cout << "Insert the elements of the set : ";
        for (int i = 0; i < n; ++i) {
            in >> __tmp;
            obj.A->insertAfter(__tmp);
        }
        obj.transform(*obj.A);
    }

    return in;
}

template <class T>
ostream &operator<<(ostream &out,const Set<T> &obj) {
    if(!obj.A->empty()) {
        out << '{';
        for (Node<T> *cross = obj.A->begin(); cross != obj.A->end(); cross = cross->getNext())
            out << cross->getX() << ',';
        out << obj.A->end()->getX() << '}';
    }
    else {
        out << "The set that you are trying to print is empty!";
    }
    return out;
}

Set<IntegerPair> produs(const Set<int> &X, const Set<int> &Y) {
    Set<IntegerPair> res;
    IntegerPair aux;
    Node<int> * cross1 = X.A->begin();

    while(cross1 != nullptr) {
        Node<int> *cross2 = Y.A->begin();
        while(cross2 != nullptr) {
            aux.first() = cross1->getX();
            aux.second() = cross2->getX();
            cross2 = cross2->getNext();
            res.A->insertAfter(aux);
        }
        cross1 = cross1->getNext();
    }
    res.transform(*res.A);

    return res;
}
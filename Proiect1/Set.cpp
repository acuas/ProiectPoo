//
// Created by auras on 21.03.2018.
// Last modified by auras on 26.03.2018
//

#include <iostream>
#include "Set.h"

Set::Set() {
    A = new LinkedList;
}

Set::Set(const LinkedList &B) {
    A = new LinkedList;
    (*A) = B;
    transform((*A));
}

Set::~Set() {
    delete A;
}

void Set::transform(LinkedList &B) {
    B.sort();
    B.unique();
}

Set Set::operator+(const Set &obj) {
    //declaration
    Set aux;
    Node * i = this->A->begin();
    Node * j = obj.A->begin();

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

Set Set::operator*(const Set &obj) {
    Set aux;
    Node * i = obj.A->begin();
    Node * j = this->A->begin();

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

Set Set::operator-(const Set &obj) {
    Set aux;
    Node * i = obj.A->begin();
    Node * j = this->A->begin();

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

Set &Set::operator=(const Set &obj) {
    if(this == &obj)
        return *this;

    if(!A->empty())
        A->clear();

    for(Node * cross = obj.A->begin(); cross != nullptr; cross = cross->getNext())
        A->insertAfter(cross->getX());

    return *this;

}

istream &operator>>(istream &in, Set &obj) {
    long long n;
    do {
        cout << "Number of elements : ";
        in >> n;
        if(n < 0 || n > INF)
            cout << "The number of the elements need to be in range [0, " << INF << "]\n";
    }while(n < 0 || n > INF);

    if(n > 0) {
        int __tmp;
        cout << "Insert the elements of the set : ";
        for (int i = 0; i < n; ++i) {
            in >> __tmp;
            obj.A->insertAfter(__tmp);
        }
        obj.transform(*obj.A);
    }

    return in;
}

ostream &operator<<(ostream &out,const Set &obj) {
    if(!obj.A->empty()) {
        out << '{';
        for (Node *cross = obj.A->begin(); cross != obj.A->end(); cross = cross->getNext())
            out << cross->getX() << ',';
        out << obj.A->end()->getX() << '}';
    }
    else {
        out << "The set that you are trying to print is empty!";
    }
    return out;
}
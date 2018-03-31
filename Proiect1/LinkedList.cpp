//
// Created by auras on 18.03.2018.
// Last Modified by auras on 26.03.2018
//
#include <iostream>
#include "LinkedList.h"

template class LinkedList<int>;
template class LinkedList<IntegerPair>;

template istream &operator>> <int>(istream &, LinkedList<int> &);
template istream &operator>> <IntegerPair>(istream &, LinkedList<IntegerPair> &);

template ostream &operator<< <int>(ostream &, const LinkedList<int> &);
template ostream &operator<< <IntegerPair>(ostream &, const LinkedList<IntegerPair> &);

template <class T>
LinkedList<T>::LinkedList() {
    first = last = nullptr;
    top = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    first = last = nullptr;
    top = 0;
    Node<T> * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    while(first) {
        popFront();
    }

    first = last = nullptr;
}

template <class T>
void LinkedList<T>::insertFront(T x) {
    ++top;
    auto * elem = new Node<T>(x);
    elem->setNext(first);
    if(first == nullptr) {
        first = last = elem;
    }
    else {
        first = elem;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T x) {
    ++top;
    auto * elem = new Node<T>(x);
    elem->setNext(nullptr);
    if(last == nullptr) {
        first = last = elem;
    }
    else {
        last->setNext(elem);
        last = elem;
    }
}

template <class T>
void LinkedList<T>::popFront() {
    if(first != nullptr) {
        --top;
        Node<T> * __tmp = first;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            first = first->getNext();
        }
        delete __tmp;
    }
}

template <class T>
void LinkedList<T>::popLast() {
    if(last != nullptr) {
        --top;
        Node<T> * __tmp = last;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            Node<T> * cross = first;
            while(cross->getNext() != last) {
                cross = cross->getNext();
            }
            cross->setNext(nullptr);
            last = cross;
        }
        delete __tmp;
    }
}

template <class T>
void LinkedList<T>::popValue(T x) {
    if(first != nullptr) {
        while(first != nullptr && first->getX() == x) {
            popFront();
            --top;
        }
        while(last != nullptr && last->getX() == x) {
            popLast();
            --top;
        }

        Node<T> *__tmp = nullptr;
        Node<T> * cross = first;
        while(cross && cross->getNext()){
            if(cross->getNext()->getX() == x) {
                --top;
                __tmp = cross->getNext();
                cross->setNext(cross->getNext()->getNext());
                delete __tmp;
            }
            else cross = cross->getNext();
        }
    }
}

template <class T>
void LinkedList<T>::popNode(Node<T> *p) {
    if(first != nullptr) {
        if(first == p) {
            --top;
            popFront();
        }
        else if(last == p) {
            --top;
            popLast();
        }
        else if(first == last) {
            ;
        }
        else {
            Node<T> * cross = first;
            Node<T> * preCross = nullptr;
            while(cross != nullptr) {
                if(cross == p)
                    break;
                preCross = cross;
                cross = cross->getNext();
            }
            if(preCross != nullptr && cross != nullptr && cross == p) {
                --top;
                preCross->setNext(cross->getNext());
                delete cross;
            }

        }
    }
}

template <class T>
int LinkedList<T>::size() {
    return this->top;
}

template <class T>
Node<T> &LinkedList<T>::operator[](const int index) {
    assert(index >= 0 && index < top); //testeaza daca index-ul se afla in range-ul listei

    if(index == 0)
        return *first;
    else if(index == top - 1)
        return *last;

    Node<T> * cross = first;
    int count = 0;

    while(count < index && cross != last) {
        ++count;
        cross = cross->getNext();
    }

    return *cross;
}

template <class T>
bool LinkedList<T>::empty() {
    return first == nullptr;
}

template <class T>
void LinkedList<T>::clear() {
    while(!empty())
        this->popFront();
}

template <class T>
int LinkedList<T>::lomuto(int lo , int hi) {
    Node<T> pivot = (*this)[hi];

    int i = lo - 1;

    for(int j = lo; j < hi; ++j) {
        if((*this)[j] < pivot) {
            ++i;
            swap((*this)[i], (*this)[j]);
        }
    }

    swap((*this)[i + 1], (*this)[hi]);
    return i + 1;
}

template <class T>
void LinkedList<T>::qsort(int lo, int hi) {
    if(lo < hi) {
        int pivot = lomuto(lo, hi);

        qsort(lo, pivot - 1);
        qsort(pivot + 1, hi);
    }
}

template <class T>
void LinkedList<T>::sort() {
    qsort(0, top - 1);
}

template <class T>
void LinkedList<T>::unique() {
    for(int i = 0; i < top - 1; ) {
        if((*this)[i] == (*this)[i + 1]) {
            popNode(&(*this)[i + 1]);
        }
        else ++i;
    }
}

template <class T>
Node<T> *LinkedList<T>::begin() {
    return first;
}

template <class T>
Node<T> *LinkedList<T>::end() {
    return last;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &obj) {
    if(this == &obj)
        return *this;

    //delete everything from the current list
    this->clear();

    //make deep copy of the list from instance obj
    Node<T> * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }

    return *this;
}

template <class T>
bool LinkedList<T>::operator<(const LinkedList<T> &obj) const{
    if(obj.top == this->top) {
        Node<T> * cross1 = this->first;
        Node<T> * cross2 = obj.first;

        while(cross1 != nullptr && cross2 != nullptr) {
            if(*cross1 < *cross2) {
                return true;
            }
            else if(*cross1 > *cross2) {
                return false;
            }
            cross1 = cross1->getNext();
            cross2 = cross2->getNext();
        }

        return false;
    }
    else return this->top < obj.top;
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &obj) const{
    if(this->top == obj.top) {
        Node<T> * cross1 = this->first;
        Node<T> * cross2 = obj.first;
        bool flag = true;

        while(cross1 != nullptr && cross2 != nullptr) {
            if(*cross1 != *cross2) {
                flag = false;
                break;
            }
            cross1 = cross1->getNext();
            cross2 = cross2->getNext();
        }

        return flag;
    }

    return false;
}

template <class T>
bool LinkedList<T>::operator!=(const LinkedList<T> &obj) const{
    return *this == obj ? false : true;
}

template <class T>
istream &operator>>(istream &in, LinkedList<T> &obj) {
    long long n;
    do {
        cout << "Number of elements : ";
        in >> n;
        if(n < 0 || n > INF)
            cout << "The number of the elements need to be in range [0, " << INF << "]\n";
    }while(n < 0 || n > INF);

    if(n > 0) {
        T __tmp;
        cout << "Insert the elements of the LinkedList : ";
        for (int i = 0; i < n; ++i) {
            in >> __tmp;
            obj.insertAfter(__tmp);
        }
    }

    return in;
}

template <class T>
ostream &operator<<(ostream &out, const LinkedList<T> &obj) {
    Node<T> * cross = obj.first;
    while(cross != nullptr) {
        out << cross->getX() << ' ';
        cross = cross->getNext();
    }
    return out;
}
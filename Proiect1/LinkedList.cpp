//
// Created by auras on 18.03.2018.
//

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    first = last = nullptr;
    top = 0;
}

LinkedList::LinkedList(const LinkedList &obj) {
    Node * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }
}

LinkedList::~LinkedList() {
    while(first) {
        popFront();
    }

    first = last = nullptr;
}

void LinkedList::insertFront(int x) {
    ++top;
    auto * elem = new Node(x);
    elem->setNext(first);
    if(first == nullptr) {
        first = last = elem;
    }
    else {
        first = elem;
    }
}

void LinkedList::insertAfter(int x) {
    ++top;
    auto * elem = new Node(x);
    elem->setNext(nullptr);
    if(last == nullptr) {
        first = last = elem;
    }
    else {
        last->setNext(elem);
        last = elem;
    }
}

void LinkedList::popFront() {
    if(first != nullptr) {
        --top;
        Node * __tmp = first;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            first = first->getNext();
        }
        delete __tmp;
    }
}

void LinkedList::popLast() {
    if(last != nullptr) {
        --top;
        Node * __tmp = last;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            Node * cross = first;
            while(cross->getNext() != last) {
                cross = cross->getNext();
            }
            cross->setNext(nullptr);
            last = cross;
        }
        delete __tmp;
    }
}

void LinkedList::popValue(int x) {
    if(first != nullptr) {
        while(first != nullptr && first->getX() == x) {
            popFront();
            --top;
        }
        while(last != nullptr && last->getX() == x) {
            popLast();
            --top;
        }

        Node *__tmp = nullptr;
        Node * cross = first;
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

void LinkedList::popNode(Node *p) {
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
            Node * cross = first;
            Node * preCross = nullptr;
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

int LinkedList::size() {
    return this->top;
}

Node &LinkedList::operator[](const int index) {
    assert(index >= 0 && index < top); //testeaza daca index-ul se afla in range-ul listei

    if(index == 0)
        return *first;
    else if(index == top - 1)
        return *last;

    Node * cross = first;
    int count = 0;

    while(count < index && cross != last) {
        ++count;
        cross = cross->getNext();
    }

    return *cross;
}

bool LinkedList::empty() {
    return first == nullptr;
}

void LinkedList::clear() {
    while(!empty())
        this->popFront();
}

int LinkedList::lomuto(int lo , int hi) {
    Node pivot = (*this)[hi];

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

void LinkedList::qsort(int lo, int hi) {
    if(lo < hi) {
        int pivot = lomuto(lo, hi);

        qsort(lo, pivot - 1);
        qsort(pivot + 1, hi);
    }
}

void LinkedList::sort() {
    qsort(0, top - 1);
}

void LinkedList::unique() {
    for(int i = 0; i < top - 1; ) {
        if((*this)[i] == (*this)[i + 1]) {
            popNode(&(*this)[i + 1]);
        }
        else ++i;
    }
}

Node *LinkedList::begin() {
    return first;
}

Node *LinkedList::end() {
    return last;
}

LinkedList &LinkedList::operator=(const LinkedList &obj) {
    if(this == &obj)
        return *this;

    //delete everything from the current list
    this->clear();

    //make deep copy of the list from instance obj
    Node * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }

    return *this;
}

ostream &operator<<(ostream &out, const LinkedList &obj) {
    Node * cross = obj.first;
    while(cross != nullptr) {
        out << cross->getX() << ' ';
        cross = cross->getNext();
    }
    return out;
}
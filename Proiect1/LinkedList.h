//
// Created by auras on 18.03.2018.
// Last modified by auras on 26.03.2018
//

#ifndef PROIECT1_LINKEDLIST_H
#define PROIECT1_LINKEDLIST_H

#include "Node.h"
#include <ostream>
#include <cassert>

using namespace std;

template <class T> class LinkedList;

template <class T>
extern ostream &operator<<(ostream &, const LinkedList<T> &);

template <class T>
extern istream &operator>>(istream &, LinkedList<T> &);

template <class T>
class LinkedList{
    private:
        Node<T> * first, *last;
        int top; //variabila automatica se aloca pe stack sau heap(in acelasi segment de memorie)
        Node<T> &operator[](int);
        int lomuto(int, int);
        void qsort(int, int);
    public:
        //Constructor and destructor
        LinkedList();
        LinkedList(const LinkedList &);
        ~LinkedList();

        //Methods to manipulate the LinkedList

        void insertFront(T);
        void insertAfter(T);
        void popFront();
        void popLast();
        void popValue(T);
        void popNode(Node<T> *);
        void clear();
        void sort();
        void unique();
        int size();
        bool empty();
        Node<T> *begin();
        Node<T> *end();

        //Operator overloading
        LinkedList &operator=(const LinkedList &);
        bool operator<(const LinkedList &) const;
        bool operator==(const LinkedList &) const;
        bool operator!=(const LinkedList &) const;

        friend istream &operator>> <T>(istream &, LinkedList<T> &);
        friend ostream &operator<< <T>(ostream &, const LinkedList<T> &);
};


#endif //PROIECT1_LINKEDLIST_H

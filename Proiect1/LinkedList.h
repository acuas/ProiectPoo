//
// Created by auras on 18.03.2018.
//

#ifndef PROIECT1_LINKEDLIST_H
#define PROIECT1_LINKEDLIST_H


#include "Node.h"
#include <ostream>
#include <cassert>

using namespace std;

class LinkedList{
    private:
        Node * first, *last;
        int top; //variabila automatica se aloca pe stack sau heap(in acelasi segment de memorie)
        Node &operator[](int);
        int lomuto(int, int);
        void qsort(int, int);
    public:
        //Constructor and destructor
        LinkedList();
        LinkedList(const LinkedList &);
        ~LinkedList();

        //Methods to manipulate the LinkedList

        void insertFront(int);
        void insertAfter(int);
        void popFront();
        void popLast();
        void popValue(int);
        void popNode(Node *);
        void clear();
        void sort();
        void unique();
        int size();
        bool empty();
        Node *begin();
        Node *end();

        //Operator overloading
        LinkedList &operator=(const LinkedList &);

        friend ostream &operator<<(ostream &, const LinkedList &);
};


#endif //PROIECT1_LINKEDLIST_H

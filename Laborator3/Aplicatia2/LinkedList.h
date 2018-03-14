//
// Created by auras on 13.03.2018.
//

#ifndef APLICATIA1_LINKEDLIST_H
#define APLICATIA1_LINKEDLIST_H
#include "Node.h"
#include <cstdio>
#include <ostream>

using namespace std;

class LinkedList {
    private :
        Node *first, *last;
    public :
        LinkedList();
        ~LinkedList();
        void insertFront(int);
        void insertAfter(int);
        void deleteFront();
        void deleteLast();
        void deleteVal(int);
        friend ostream& operator<<(ostream &output, LinkedList &obj);
};


#endif //APLICATIA1_LINKEDLIST_H

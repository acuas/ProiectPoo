//
// Created by auras on 13.03.2018.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    first = last = NULL;
}

LinkedList::~LinkedList() {
    while(first != NULL)
        deleteFront();
}

void LinkedList::insertFront(int x) {
    Node * new_node = new Node(x);
    new_node->setNext(first);
    first = new_node;
    if(last == NULL) {
        last = first;
    }
}

void LinkedList::insertAfter(int x) {
    Node * new_node = new Node(x);
    new_node->setNext(NULL);
    if(last == NULL) {
        first = last = new_node;
    }
    else {
        last->setNext(new_node);
        last = new_node;
    }
}

void LinkedList::deleteFront() {
    if(first != NULL) {
        Node *__tmp = first;
        if(first == last) {
            first = last = NULL;
        }
        else {
            first = first->getNext();
        }
        delete __tmp;
    }
}

void LinkedList::deleteLast() {
    if(last != NULL) {
        Node *__tmp = last;
        if(first == last) {
            first = last = NULL;
        }
        else {
            Node * cross = first;
            while(cross->getNext() != last) {
                cross = cross->getNext();
            }
            last = cross;
            last->setNext(NULL);
        }
        delete __tmp;
    }
}

void LinkedList::deleteVal(int x) {
    if(first != NULL) {
        if(first->getVal() == x) {
            deleteFront();
        }
        else if(last->getVal() == x) {
            deleteLast();
        }
        else if(first == last)
            ;
        else {
            Node * cross = first;

            while(cross->getNext() != last && cross->getNext()->getVal() != x) {
                cross = cross->getNext();
            }
            if(cross->getNext()->getVal() == x) {
                Node *__tmp = cross->getNext();
                cross->setNext(cross->getNext()->getNext());

                delete __tmp;
            }
        }
    }
}

ostream& operator<<(ostream &output, LinkedList &obj) {
    Node *cross = obj.first;
    while(cross != NULL) {
        output << cross->getVal() <<' ';
        cross = cross->getNext();
    }
    return output;
}
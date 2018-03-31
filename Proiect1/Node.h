//
// Created by auras on 18.03.2018.
// Last modified by auras on 26.03.2018
// Nu este necesara supraincarcarea constructorului de copiere
// si a operatorului de atribuire deoarece datele clasei sunt retinute
// intr-o variabila automatica
//

#ifndef PROIECT1_NODE_H
#define PROIECT1_NODE_H

#include "IntegerPair.h"

template <class T> class Node;

template <class T>
extern void swap(Node<T> &A, Node<T> &B);

template <class T>
class Node {
    private:
        T x;
        Node * next;
    public:
        explicit Node(T);

        T getX();
        void setX(T);
        Node *getNext();
        void setNext(Node *);

        //Operator overloading
        bool operator<(const Node<T> &) const;
        bool operator>(const Node<T> &) const;
        bool operator<=(const Node<T> &) const;
        bool operator>=(const Node<T> &) const;
        bool operator!=(const Node<T> &) const;
        bool operator==(const Node<T> &) const;

        friend void swap<T>(Node &A, Node &B); //overload swap for sorting algorithm
};

#endif //PROIECT1_NODE_H

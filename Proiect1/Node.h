//
// Created by auras on 18.03.2018.
//

#ifndef PROIECT1_NODE_H
#define PROIECT1_NODE_H


class Node {
    private:
        int x;
        Node * next;
    public:
        explicit Node(int);
        int getX();
        void setX(int);
        Node *getNext();
        void setNext(Node *);

        friend bool operator<(const Node &, const Node &);
        friend bool operator>(const Node &, const Node &);
        friend bool operator<=(const Node &, const Node &);
        friend bool operator>=(const Node &, const Node &);
        friend bool operator!=(const Node &, const Node &);
        friend bool operator==(const Node &, const Node &);
        friend void swap(Node &, Node &); //overload swap for sorting algorithm
};


#endif //PROIECT1_NODE_H

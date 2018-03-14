//
// Created by auras on 13.03.2018.
//

#ifndef APLICATIA1_NODE_H
#define APLICATIA1_NODE_H


class Node {
    private:
        int val;
        Node *next;
    public:
        explicit Node(int);
        void setVal(int);
        int getVal();
        void setNext(Node *next);
        Node *getNext();
};


#endif //APLICATIA1_NODE_H

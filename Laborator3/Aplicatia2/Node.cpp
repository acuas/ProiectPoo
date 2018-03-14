//
// Created by auras on 13.03.2018.
//

#include <cstdio>
#include "Node.h"

Node::Node(int x = 0) {
    setVal(x);
    this->next = NULL;
}

void Node::setVal(int val) {
    this->val = val;
}

int Node::getVal() {
    return this->val;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Node* Node::getNext() {
    return this->next;
}
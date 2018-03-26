//
// Created by auras on 18.03.2018.
//

#include "Node.h"

Node::Node(int x = 0) {
    this->x = x;
    this->next = nullptr;
}

int Node::getX() {
    return x;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setNext(Node * next) {
    this->next = next;
}

void Node::setX(int x = 0) {
    this->x = x;
}

bool operator<(const Node &A, const Node &B) {
    return A.x < B.x;
}

bool operator>(const Node &A, const Node &B) {
    return A.x > B.x;
}

bool operator<=(const Node &A, const Node &B) {
    return A.x <= B.x;
}

bool operator>=(const Node &A, const Node &B) {
    return A.x >= B.x;
}

bool operator!=(const Node &A, const Node &B) {
    return A.x != B.x;
}

bool operator==(const Node &A, const Node &B) {
    return A.x == B.x;
}

void swap(Node &A, Node &B) {
    int __tmp = B.x;
    B.x = A.x;
    A.x = __tmp;
}
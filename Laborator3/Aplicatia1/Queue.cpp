//
// Created by auras on 14.03.2018.
//

#include "Queue.h"

Queue::Queue() {
    S1 = new Stack();
    S2 = new Stack();
}

Queue::~Queue() {
    delete S1;
    delete S2;
}

void Queue::push_back(int x) {
    S1->push(x);
}

void Queue::pop_front() {
    while(!S1->empty()) {
        S2->push(S1->back());
        S1->pop();
    }

    S2->pop();
    while(!S2->empty()) {
        S1->push(S2->back());
        S2->pop();
    }
}

int Queue::size() {
    return S1->size();
}

bool Queue::empty() {
    return S1->empty();
}

int Queue::back() {
    return S1->back();
}

int Queue::front() {
    while(!S1->empty()) {
        S2->push(S1->back());
        S1->pop();
    }

    int __tmp = S2->back();

    while(!S2->empty()) {
        S1->push(S2->back());
        S2->pop();
    }

    return __tmp;
}
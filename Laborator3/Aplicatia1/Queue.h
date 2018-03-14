//
// Created by auras on 14.03.2018.
//

#ifndef APLICATIA2_QUEUE_H
#define APLICATIA2_QUEUE_H
#include "Stack.h"

class Queue {
    private:
        Stack *S1, *S2;
    public:
        Queue();
        ~Queue();
        void push_back(int);
        void pop_front();
        int size();
        bool empty();
        int back();
        int front();
};

#endif //APLICATIA2_QUEUE_H

//
// Created by auras on 14.03.2018.
//

#ifndef APLICATIA2_STACK_H
#define APLICATIA2_STACK_H
#include <iostream>
#include <cstdio>

using namespace std;

class Stack{
private :
    int top, *st;
public :
    Stack();
    ~Stack();
    int size();
    void push(int x);
    bool empty();
    int back();
    void pop();
};


#endif //APLICATIA2_STACK_H

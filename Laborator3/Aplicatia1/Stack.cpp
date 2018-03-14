//
// Created by auras on 14.03.2018.
//

#include "Stack.h"

Stack::Stack() {
    top = 0;
    st = NULL;
}

Stack::~Stack() {
    top = 0;
    delete[] st;
}

int Stack::size() {
    return top;
}

void Stack::push(int x) {
    if(top == 0) {
        ++top;
        st = new int[1];
        st[0] = x;
    }
    else {
        ++top;
        int *tmp = new int[top];
        for (int i = 0; i < top - 1; ++i) {
            tmp[i] = st[i];
        }

        tmp[top - 1] = x;
        delete[] st;

        st = tmp;
    }
}

void Stack::pop() {
    if(top == 0) {
        cout << "The stack is empty! This operation is denied!\n";
    }
    else {
        int *tmp = new int[top - 1];
        for(int i = 0; i < top - 1; ++i) {
            tmp[i] = st[i];
        }

        --top;
        delete[] st;
        st = tmp;
    }
}

int Stack::back() {
    if(top > 0) {
        return st[top - 1];
    }
}

bool Stack::empty() {
    return top == 0;
}
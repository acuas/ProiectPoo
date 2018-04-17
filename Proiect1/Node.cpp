//
// Created by auras on 18.03.2018.
// Last modified by auras on 26.03.2018
//

#include "Node.h"

template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<IntegerPair>;

template void swap<int>(Node<int> &A, Node<int> &B);
template void swap<float>(Node<float> &A, Node<float> &B);
template void swap<double>(Node<double> &A, Node<double> &B);
template void swap<IntegerPair>(Node<IntegerPair> &A, Node<IntegerPair> &B);

template <class T>
Node<T>::Node(T x) {
    this->x = x;
    this->next = nullptr;
}

template <class T>
T Node<T>::getX() {
    return x;
}

template <class T>
void Node<T>::setX(T x) {
    this->x = x;
}

template <class T>
Node<T> *Node<T>::getNext() {
    return this->next;
}

template <class T>
void Node<T>::setNext(Node<T> * next) {
    this->next = next;
}

template <class T>
bool Node<T>::operator<(const Node<T> &B) const{
    return this->x < B.x;
}

template <class T>
bool Node<T>::operator>(const Node<T> &B) const{
    return this->x > B.x;
}

template <class T>
bool Node<T>::operator<=(const Node<T> &B) const{
    return this->x <= B.x;
}

template <class T>
bool Node<T>::operator>=(const Node<T> &B) const{
    return this->x >= B.x;
}

template <class T>
bool Node<T>::operator!=(const Node<T> &B) const{
    return this->x != B.x;
}

template <class T>
bool Node<T>::operator==(const Node<T> &B) const{
    return this->x == B.x;
}

template <class T>
void swap(Node<T> &A, Node<T> &B) {
    T __tmp = A.x;
    A.x = B.x;
    B.x = __tmp;
}

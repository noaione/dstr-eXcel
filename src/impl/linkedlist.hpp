#ifndef EXCEL_IMPL_LL_HPP
#define EXCEL_IMPL_LL_HPP

#include "base.hpp"

template <class T> class Node
{
    T data;
    Node *next, *prev;

public:
    Node(T data);
    T getData();
    void setData(T data);
    Node *getNext();
    void setNext(Node *next);
    void detach();
};

template <class T> class LinkedList : public Iterable<T> {
private:
    Node<T> *curr, *head, *tail;
    void popTail();
    void popHead();

public:
    LinkedList();
    void insert(T data);
    void insert(T data, int index);
    void insert(T data, bool (*comparator)(T*, T*));
    void remove(T data);
    void remove(T data, bool (*comparator)(T*, T*));
    void remove(int index);

    T get();
    T get(int index);

    long int getCapacity() {
        return -1;
    }

    // iteration stuff
    T next();
    void resetIndex();
};

#endif /* EXCEL_IMPL_LL_HPP */
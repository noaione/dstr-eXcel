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
    void insert(T data) override;
    void insert(T data, int index) override;
    void insert(T data, bool (*comparator)(T*, T*)) override;
    void remove(T data) override;
    void remove(T data, bool (*comparator)(T*, T*)) override;
    void remove(int index) override;

    T get() override;
    T get(int index) override;
    long int getCount() override;

    // iteration stuff
    T next() override;
    void resetIndex() override;
};

#endif /* EXCEL_IMPL_LL_HPP */
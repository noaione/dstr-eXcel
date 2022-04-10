#ifndef EXCEL_LL_IMPL_HPP
#define EXCEL_LL_IMPL_HPP

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

template <class T> class LinkedList
{
    Node<T> *curr, *head, *tail;

public:
    LinkedList();
    void insert(T data);
    void insertMid(T data, bool (*comparator)(T*, T*));
    void remove(T data);
private:
    void popTail();
    void popHead();
};

#endif /* EXCEL_LL_IMPL_HPP */
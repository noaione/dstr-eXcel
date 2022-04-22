#include <cstdlib>

#include "linkedlist.hpp"

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template <class T>
T Node<T>::getData() {
    return this->data;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

template <class T>
void Node<T>::setNext(Node *next) {
    this->next = next;
}

template <class T>
void Node<T>::detach() {
    this->next = NULL;
    this->prev = NULL;
}

template <class T>
LinkedList<T>::LinkedList() {
    head = tail = curr = NULL;
}

template <class T>
void LinkedList<T>::insert(T data) {
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = temp->prev = NULL;

    if (this->head == NULL) {
        this->head = this->tail = temp;
    } else {
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
    this->_count++;
}

template <class T>
void LinkedList<T>::insert(T data, bool (*comparator)(T*, T*)) {
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = temp->prev = NULL;

    if (this->head == NULL) {
        this->head = this->tail = temp;
    } else {
        int currIdx = 0;
        this->curr = this->head;
        while (this->curr->next != NULL) {
            if (comparator(&this->curr->data, &data)) {
                temp->next = this->curr;
                temp->prev = this->curr->prev;
                this->curr->prev->next = temp;
                this->curr->prev = temp;
                break;
            }
            currIdx++;
        }
        // reset current index
        this->_index = currIdx + 1;
    }
    this->_count++;
}

template <class T>
void LinkedList<T>::insert(T data, int index) {
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = temp->prev = NULL;

    if (this->head == NULL) {
        // ignore index
        this->head = this->tail = temp;
    } else {
        // insert at the target index
        if (index == 0) {
            temp->next = this->head;
            this->head->prev = temp;
            this->head = temp;
        } else if (index >= this->_count) {
            this->tail->next = temp;
            temp->prev = this->tail;
            this->tail = temp;
        } else {
            int currIdx = 0;
            this->curr = this->head;
            while (this->curr->next != NULL) {
                if (currIdx == index) {
                    temp->next = this->curr;
                    temp->prev = this->curr->prev;
                    this->curr->prev->next = temp;
                    this->curr->prev = temp;
                    break;
                }
                currIdx++;
            }
            // reset current index
            this->_index = currIdx + 1;
        }
    }
    this->_count++;
}
#include <cstdlib>
#include "impl.hpp"

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
    this->head = NULL;
    this->tail = NULL;
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
}

template <class T>
void LinkedList<T>::insertMid(T data, bool (*comparator)(T*, T*)) {
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = temp->prev = NULL;

    if (this->head == NULL) {
        this->head = this->tail = temp;
    } else {
        Node<T> *curr = this->head;
        while (curr != NULL) {
            if (comparator(&curr->data, &data)) {
                temp->next = curr;
                temp->prev = curr->prev;
                curr->prev->next = temp;
                curr->prev = temp;
                break;
            }
            curr = curr->next;
        }
    }
}

template <class T>
void LinkedList<T>::popHead() {
    if (this->head && this->head == this->tail) {
        this->head = this->tail = NULL;
        delete this->head;
    } else {
        Node<T> *headC = this->head->next;
        this->head->next = headC->prev = NULL;
        delete this->head;
        this->head = headC;
    }
}

template <class T>
void LinkedList<T>::popTail() {
    if (this->head && this->head == this->tail) {
        this->head = this->tail = NULL;
        delete this->head;
    } else {
        Node<T> *tailC = this->tail->prev;
        this->tail->prev = tailC->next = NULL;
        delete this->tail;
        this->tail = tailC;
    }
}

template <class T>
void LinkedList<T>::remove(T data) {
    if (!this->head) {
        return;
    } else if (this->head == data) {
        this->popHead();
    } else if (this->tail == data) {
        this->popTail();
    } else {
        this->curr = this->head;
        while (curr && curr == data) {
            curr = curr->next;
        }

        // check if curr is empty.
        if (!curr) {
            return;
        }

        this->curr->prev->next = this->curr->next;
        this->curr->next->prev = this->curr->prev;

        this->curr->prev = this->curr->next = NULL;
        delete this->curr;
    }
}
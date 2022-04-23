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
    this->head = this->tail = this->curr = NULL;
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
bool simpleCompare(T* a, T* b) {
    if (*a == *b) {
        return true;
    }
    return false;
}

template <class T>
void LinkedList<T>::remove(T data, bool (*comparator)(T*, T*)) {
    int index = 0;
    if (!this->head) {
        return;
    } else if (comparator(this->tail->data, data)) {
        this->popHead();
    } else if (comparator(this->tail->data, data)) {
        this->popTail();
    } else {
        this->curr = this->head;
        while (curr && comparator(this->curr->data, data)) {
            this->curr = this->curr->next;
            index++;
        }

        // check if curr is empty.
        if (!this->curr) {
            return;
        }

        this->curr->prev->next = this->curr->next;
        this->curr->next->prev = this->curr->prev;

        this->curr->prev = this->curr->next = NULL;
        delete this->curr;
    }
    this->_count--;
    if (index > this->_index) {
        this->_index--;
    }
}
template <class T>
void LinkedList<T>::remove(T data) {
    this->remove(data, simpleCompare);
}
template <class T>
void LinkedList<T>::remove(int index) {
    if (index <= 0) {
        this->_index--;
        this->popHead();
        return;
    }
    if (index >= this->_count) {
        this->popTail();
        return;
    }

    int currIdx = 0;
    this->curr = this->head;
    while (this->curr->next != NULL) {
        if (currIdx == index) {
            this->curr->prev->next = this->curr->next;
            this->curr->next->prev = this->curr->prev;

            this->curr->prev = this->curr->next = NULL;
            delete this->curr;
            break;
        }
        currIdx++;
    }
    if (index > this->_index) {
        this->_index--;
    }
    this->_count--;
}

template <class T>
T LinkedList<T>::get() {
    return this->curr->data;
};
template <class T>
T LinkedList<T>::get(int index) {
    return this->curr->data;
}

template <class T>
T LinkedList<T>::next() {
    if (this->curr->next) {
        this->curr = this->curr->next;
    } else {
        return NULL;
    }
    return this->curr->data;
}
template <class T>
void LinkedList<T>::resetIndex() {
    this->_index = 0;
}
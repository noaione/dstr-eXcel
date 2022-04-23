#include <cstdlib>
#include <array>

#include "arraystruct.hpp"

template <class T>
ArrayStruct<T>::ArrayStruct() {
    this->_internalArray = std::array<T, 100>{};
}

template <class T>
void ArrayStruct<T>::insert(T data) {
    this->_internalArray[this->_count] = data;
    this->_count++;
}
template <class T>
void ArrayStruct<T>::insertHead(T data) {
    // push everything to the right
    for (int i = this->_count; i > 0; i--) {
        this->_internalArray[i] = this->_internalArray[i - 1];
    }
    this->_internalArray[0] = data;
    this->_count++;
}
template <class T>
void ArrayStruct<T>::insert(T data, int index) {
    if (index < 0) {
        this->insertHead(data);
        return;
    }
    if (index >= this->_count) {
        this->insert(data);
        return;
    }

    for (int i = this->_count; i > index; i--) {
        this->_internalArray[i] = this->_internalArray[i - 1];
    }

    this->_internalArray[index] = data;
    this->_count++;
}

template <class T>
bool simpleCompare(T* a, T* b) {
    if (*a == *b) {
        return true;
    }
    return false;
}

template <class T>
void ArrayStruct<T>::remove(T data, bool (*comparator)(T*, T*)) {
    int index = 0;
    for (int i = 0; i < this->_count; i++) {
        if (comparator(&this->_internalArray[i], &data)) {
            for (int j = i; j < this->_count; j++) {
                this->_internalArray[j] = this->_internalArray[j + 1];
            }
            this->_count--;
            index = i;
            if (index > this->_index) {
                this->_index--;
            }
            return;
        }
    }

}
template <class T>
void ArrayStruct<T>::remove(T data) {
    this->remove(data, simpleCompare);
}
template <class T>
void ArrayStruct<T>::remove(int index) {
    if (index < 0) {
        this->_index--;
        this->popHead();
        return;
    }
    if (index >= this->_count) {
        this->popTail();
        return;
    }

    for (int i = index; i < this->_count; i++) {
        this->_internalArray[i] = this->_internalArray[i + 1];
    }
    this->_count--;
    if (index > this->_index) {
        this->_index--;
    }
}

template <class T>
T ArrayStruct<T>::get() {
    this->get(this->_index);
}
template <class T>
T ArrayStruct<T>::get(int index) {
    return this->_internalArray[index];
}

template <class T>
long int ArrayStruct<T>::getCapacity() {
    return this->_internalArray.max_size();
}

template <class T>
T ArrayStruct<T>::next() {
    this->_index++;
    if (this->_index >= this->_count) {
        this->_index--;
        return NULL;
    }
    return this->_internalArray[this->_index];
}
template <class T>
void ArrayStruct<T>::resetIndex() {
    this->_index = 0;
}
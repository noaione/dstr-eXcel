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
#include <cstdlib>
#include "base.hpp"

template <class T>
void Iterable<T>::insert(T data) {
    return;
}
template <class T>
void Iterable<T>::insert(T data, int index) {
    return;
}
template <class T>
void Iterable<T>::insert(T data, bool (*comparator)(T*, T*)) {
    return;
}

template <class T>
void Iterable<T>::remove(T data) {
    return;
}
template <class T>
void Iterable<T>::remove(T data, bool (*comparator)(T*, T*)) {
    return;
}
template <class T>
void Iterable<T>::remove(int index) {
    return;
}

template <class T>
T Iterable<T>::get() {
    return NULL;
};
template <class T>
T Iterable<T>::get(int index) {
    return NULL;
}

template <class T>
long int Iterable<T>::getCount() {
    return this->_count;
}
template <class T>
long int Iterable<T>::getCapacity() {
    return 0;
}
template <class T>
long int Iterable<T>::getIndex() {
    return this->_index;
}

template <class T>
T Iterable<T>::next() {
    return NULL;
}
template <class T>
void Iterable<T>::resetIndex() {
    _index = 0;
}

template <class T>
void Iterable<T>::init() {
    _count = 0;
    _index = 0;
}
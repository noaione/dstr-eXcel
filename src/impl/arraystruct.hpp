#ifndef EXCEL_IMPL_ARRSTRUCT_HPP
#define EXCEL_IMPL_ARRSTRUCT_HPP

#include <array>
#include "base.hpp"
#define MAXIMUM_SIZE 100;

template <class T> class ArrayStruct : public Iterable<T> {
private:
    std::array<T, 100> _internalArray{};
    void insertHead(T data);
    void insertTail(T data);

public:
    ArrayStruct();
    void insert(T data);
    void insert(T data, int index);
    void insert(T data, bool (*comparator)(T*, T*));
    void remove(T data);
    void remove(T data, bool (*comparator)(T*, T*));
    void remove(int index);

    T get();
    T get(int index);

    long int getCapacity();

    // iteration stuff
    T next();
    void resetIndex();
};

#endif /* EXCEL_IMPL_ARRSTRUCT_HPP */
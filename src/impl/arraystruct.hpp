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

#endif /* EXCEL_IMPL_ARRSTRUCT_HPP */
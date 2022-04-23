#ifndef EXCEL_IMPL_BASE_HPP
#define EXCEL_IMPL_BASE_HPP

template <class T> class Iterable
{
private:
    long int _index;
    long int _count;
public:
    virtual void init();
    virtual void insert(T data);
    virtual void insert(T data, int index);
    virtual void insert(T data, bool (*comparator)(T*, T*));
    virtual void remove(T data);
    virtual void remove(T data, bool (*comparator)(T*, T*));
    virtual void remove(int index);

    virtual T get();
    virtual T get(int index);

    virtual long int getCount();
    virtual long int getCapacity();
    virtual long int getIndex();

    // iteration stuff
    virtual T next();
    virtual void resetIndex();
};

#endif /* EXCEL_IMPL_BASE_HPP */
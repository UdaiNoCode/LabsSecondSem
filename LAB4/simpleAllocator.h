//
// Created by udainoko on 3/9/25.
//

#ifndef LAB4_SIMPLEALLOCATOR_H
#define LAB4_SIMPLEALLOCATOR_H
#include <iostream>
using size_type = size_t;

template <class T> class simpleAllocator {


public:
    simpleAllocator() = default;
    ~simpleAllocator() = default;

public:
    T *allocate(size_type n){
        return reinterpret_cast<T*>(::operator new(sizeof(T) * n));
    }// allocate memory

    void deallocate(T* ptr,  size_type){
        if(ptr) {
            ::operator delete(ptr);
        }
    }// deallocate memory

    void construct(T* ptr, const T& temp){
        new(ptr) T(temp);
    }

    void destroy(T* ptr) noexcept{
        ptr->~T();
    }
};


#endif //LAB4_SIMPLEALLOCATOR_H

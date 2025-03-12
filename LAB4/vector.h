//
// Created by udainoko on 3/10/25.
//

#ifndef LAB4_VECTOR_H
#define LAB4_VECTOR_H
#include "simpleAllocator.h"
#include <cstddef>
#include <initializer_list>

namespace myStd {

    template<typename T, typename Allocator = simpleAllocator<T>>
    class vector {
        //* Constructors *//
    public:
        vector() noexcept;
        ~vector();

    private:
        size_t size;
        size_t capacity;
        Allocator allocator;
        T* arr;

    };


} // myStd

#endif //LAB4_VECTOR_H

//
// Created by udainoko on 3/10/25.
//

#ifndef TASK4_VECTOR_H
#define TASK4_VECTOR_H

#include "simpleAllocator.h"
#include <exception>
#include <initializer_list>
#include <iterator>
#include <algorithm>
#include <iostream>

#define MAX_SIZE_VECTOR 2305843009213693951;

namespace myStd {
template<typename T, typename Allocator = SimpleAllocator<T>>
    class vector {


    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef const T& const_reference;
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef const std::reverse_iterator<iterator> const_reverse_iterator;
        typedef size_t size_type;
    public:
        vector() noexcept;
        vector(std::initializer_list<T> list);
        ~vector();

    public:
        value_type operator[] (size_type index);
        value_type operator[] (size_type index) const;
    public:
        size_type size() const noexcept;
        size_type capacity() const noexcept;

    public:
        void push_back(const_reference value);
        void push_back(value_type &&value);

        void resize(size_type new_size);
        void resize(size_type new_size, const T& x);

        pointer data() noexcept;
        const_pointer data() const noexcept;

        pointer back() noexcept;
        const_pointer back() const noexcept;

        pointer at(size_type n) noexcept;
        const_pointer at(size_type n) const noexcept;

        pointer front() noexcept;
        const_pointer front() const noexcept;

        void pop_back() noexcept;

        void clear() noexcept;

        void reserve(size_type new_size);

        void swap(vector<T> &x) noexcept;

        void insert(iterator position, T&& x);
        void insert(iterator position, const T&& x);
        void insert(iterator position, size_type n, const T&& x);
        void insert(iterator position,iterator input_iterator_start, iterator input_iterator_end);


        void erase(iterator position);
        void erase(iterator first, iterator last);

        size_type max_size() const noexcept;


        iterator begin() noexcept;
        const_iterator cbegin() noexcept;
        iterator end() noexcept;
        const_iterator cend() noexcept;
        reverse_iterator rbegin() noexcept;
        const_reverse_iterator crbegin() noexcept;
        reverse_iterator rend() noexcept;
        const_reverse_iterator crend() noexcept;


        bool empty() noexcept;

    private:
        size_t _size = 0;
        size_t _capacity = 4;
        T* _arr;
        Allocator _myAllocator;

       void reallocate();

    private:
        void shift_right(iterator position, size_t step = 0);
        void shift_left(iterator position_first, iterator position_end, size_t step = 0);
    };



    /* -------------------------------------------------------------------------------------------------
     * shifts
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    void vector<T, Allocator>::shift_right(vector::iterator position, size_t step) {
        std::move_backward(position, end(), end() + step);
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::shift_left(vector::iterator position_first, vector::iterator position_end, size_t step) {
        std::move(position_first + step, position_end, position_first);
    }

    /* -------------------------------------------------------------------------------------------------
     * Getters functions
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() noexcept {
        return _arr;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cbegin() noexcept {
        return _arr;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end() noexcept {
        return _arr + _size;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cend() noexcept {
        return _arr + _size;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() noexcept {
        return reverse_iterator(_arr + _size);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::crbegin() noexcept {
        return reverse_iterator(_arr + _size);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() noexcept {
        return reverse_iterator(_arr);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::crend() noexcept {
        return reverse_iterator(_arr);
    }

    /* -------------------------------------------------------------------------------------------------
     * Data
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::pointer vector<T, Allocator>::data() noexcept {
        return _arr;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_pointer vector<T, Allocator>::data() const noexcept {
        return _arr;
    }

    /* -------------------------------------------------------------------------------------------------
     * Back
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::pointer vector<T, Allocator>::back() noexcept{
        return &_arr[_size - 1];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_pointer vector<T, Allocator>::back() const noexcept {
        return &_arr[_size - 1];
    }

    /*-------------------------------------------------------------------------------------------------
     * at()
     * ------------------------------------------------------------------------------------------------*/

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::pointer vector<T, Allocator>::at(typename vector<T, Allocator>::size_type n) noexcept {
        return &_arr[n];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_pointer vector<T, Allocator>::at(typename vector<T, Allocator>::size_type n) const noexcept {
        return &_arr[n];
    }
    /* -------------------------------------------------------------------------------------------------
     * front()
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::pointer vector<T,Allocator>::front() noexcept {
        return &_arr[0];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_pointer vector<T,Allocator>::front() const noexcept {
        return &_arr[0];
    }

    /* -------------------------------------------------------------------------------------------------
     * size_type()
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const noexcept {
        return MAX_SIZE_VECTOR;
    }



    /* -------------------------------------------------------------------------------------------------
     * resize()
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    void vector<T, Allocator>::resize(typename vector<T, Allocator>::size_type new_size) {
        if(new_size > _size){
            if(new_size > _capacity){
                _capacity = new_size;
                reallocate();
            }
        }
        else{
            for(size_type i = new_size; i < _size; i++){
                _myAllocator.destroy(&_arr[i]);
            }
        }
        _size = new_size;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::resize(typename vector<T, Allocator>::size_type new_size, const T &x) {
        if(new_size > _size){
            if(new_size > _capacity){
                _capacity = new_size;
                reallocate();
            }
            for(size_type i = _size; i < new_size; ++i){
                _arr[i] = x;
            }
        }
        else{
            for(size_type i = new_size; i < _size; ++i){
                _myAllocator.destroy(&_arr[i]);
            }
        }
        _size = new_size;
    }

    /* -------------------------------------------------------------------------------------------------
     * Empty
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    bool vector<T, Allocator>::empty() noexcept {
        return _size == 0;
    }

    /* -------------------------------------------------------------------------------------------------
     * Reserve() function
     *------------------------------------------------------------------------------------------------- */
    template<typename T, typename Allocator>
    void vector<T, Allocator>::reserve(typename vector<T, Allocator>::size_type new_size) {
        if(new_size > _capacity){
            _capacity = new_size;
            reallocate();
        }
    }

    /* -------------------------------------------------------------------------------------------------
     * Clear() function
     *------------------------------------------------------------------------------------------------- */
    template<typename T, typename Allocator>
    void vector<T, Allocator>::clear() noexcept {
        for(size_type i = 0; i < _size; i++){
            _myAllocator.destroy(&_arr[i]);
        }
        _myAllocator.deallocate(_arr, _size);
        _capacity = 4;
        _size = 0;
        _arr = _myAllocator.allocate(_capacity);

    }

    /* -------------------------------------------------------------------------------------------------
     * swap()
     *------------------------------------------------------------------------------------------------- */
    template<typename T, typename Allocator>
    void vector<T, Allocator>::swap(vector<T> &x) noexcept {
        std::swap(_arr, x._arr);
        std::swap(_capacity, x._capacity);
        std::swap(_size, x._size);
    }

    /* -------------------------------------------------------------------------------------------------
     * Reallocate function
     *------------------------------------------------------------------------------------------------- */
    template<typename T, typename Allocator>
    void vector<T, Allocator>::reallocate() {
        T* ptr = _myAllocator.allocate(_capacity);
        for(size_t i = 0; i< _size; i++) {_myAllocator.construct(ptr + i, _arr[i]);}
        for(size_t i = 0; i< _size; i++) {_myAllocator.destroy(&_arr[i]);}
        _myAllocator.deallocate(_arr, _capacity);
        _arr = ptr;
    }

    /* -------------------------------------------------------------------------------------------------
     * Constructor and deconstructions
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    vector<T, Allocator>::vector() noexcept {
        _arr = _myAllocator.allocate(_capacity);
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(std::initializer_list<T> list) {
        _capacity = list.size() << 1;
        _arr = _myAllocator.allocate(_capacity);
        for(const auto &elems: list){
            _myAllocator.construct(_arr + _size, elems);
            _size ++;
        }
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::~vector() {
        _myAllocator.destroy(_arr);
        _myAllocator.deallocate(_arr, _size);

    }


    /* -------------------------------------------------------------------------------------------------
     * Capacity Functions
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    size_t vector<T, Allocator>::size() const noexcept {
        return _size;
    }

    template<typename T, typename Allocator>
    size_t vector<T, Allocator>::capacity() const noexcept {
        return _capacity;
    }

    /* -------------------------------------------------------------------------------------------------
     * Pop_back
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    void vector<T, Allocator>::pop_back() noexcept {
        _myAllocator.destroy(&_arr[_size - 1]);
        _size -= 1;
    }

    /* -------------------------------------------------------------------------------------------------
     * Push_back
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    void vector<T, Allocator>::push_back(const T &value) {
        if(_size == _capacity){
            _capacity *=2 ;
        }
        reallocate();
        _myAllocator.construct(&_arr[_size], value);
        _size ++;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::push_back(T &&value) {
        if(_size == _capacity){
            _capacity *= 2;
        }
        reallocate();
        _myAllocator.construct(&_arr[_size], std::move(value));
        _size ++;
    }

    /* -------------------------------------------------------------------------------------------------
     * insert()
     * -------------------------------------------------------------------------------------------------*/

    template<typename T, typename Allocator>
    void vector<T, Allocator>::insert(typename vector<T, Allocator>::iterator position, T &&x) {
        if(_size >= _capacity) {
            reallocate();
        }
        shift_right(position,1);
        ++_size;
        _myAllocator.construct(position, x);
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::insert(vector::iterator position, const T &&x) {
        if(_size >= _capacity) {
            reallocate();
        }
        shift_right(position,1);
        ++_size;
        _myAllocator.construct(position, x);
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::insert(vector::iterator position, vector::size_type n, const T &&x) {
        size_type index = position - begin();

        if(_size + n > _capacity){
            size_type new_size = _size + n;
            while(_capacity < new_size) {
                _capacity *= 2;
            }
            reallocate();
        }

        position = begin() + index;
        shift_right(position, n);
        _size += n;

        for(size_type i = 0; i < n; i++){
            _myAllocator.construct(&_arr[index + i], x);
        }
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::insert(vector::iterator position, vector::iterator input_iterator_start,
                                      vector::iterator input_iterator_end) {

        size_type n = input_iterator_end - input_iterator_start;
        size_type index = position - begin();

        if(_size + n > _capacity){
            size_type new_size = _size + n;
            while(_capacity < new_size) {
                _capacity *= 2;
            }
            reallocate();
        }

        position = begin() + index;
        shift_right(position, n);
        _size += n;

        for(size_type i = 0; i < n; i++){
            _myAllocator.construct(&_arr[index + i], input_iterator_start[i]);
        }
    }

    /* -------------------------------------------------------------------------------------------------
     * erase()
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    void vector<T, Allocator>::erase(vector::iterator position) {

        value_type index = position - begin();
        _myAllocator.destroy(&_arr[index]);
        shift_left(position + 1, end(), 1);
        _size -= 1;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::erase(vector::iterator first, vector::iterator last) {
        value_type range = last - first + 1;
        value_type start_pos = first - begin();
        value_type last_pos = last - begin();
        std::cout<<start_pos << " "<< last_pos<<" "<<std::endl;

        for(value_type i = start_pos; i < last_pos + 1; i++){
            _myAllocator.destroy(&_arr[i]);
        }
        shift_left(first, end(), range);
        _size -= range;
    }

    /* -------------------------------------------------------------------------------------------------
     * Operator []
     * -------------------------------------------------------------------------------------------------*/
    template<typename T, typename Allocator>
    T vector<T, Allocator>::operator[](size_t index) {

        if(index >= size()){
            throw std::out_of_range("Index out of range");
        }
        return _arr[index];
    }

    template<typename T, typename Allocator>
    T vector<T, Allocator>::operator[](size_t index) const {
        if(index >= size()){
            throw std::out_of_range("Index out of range");
        }
        return _arr[index];
    }
} // myStd

#endif //TASK4_VECTOR_H

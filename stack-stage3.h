/*
 * stack-stage3.h
 *
 * Author: Parker Young
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t


template <typename T>
class stack {
public:
    T top();

    void push(const T &);
    void pop();
    size_t size();
    bool is_empty();

    stack();
    stack(const stack<T>& other);
    stack<T>& operator=(const stack<T>& other);
    ~stack();


private:
    T* _data;
    size_t _size;
    size_t _end_idx;
};

#endif

template <typename T>
stack<T>::stack() {
    _data = new T[1];
    _size = 1;
    _end_idx = 0;
}

template <typename T>
stack<T>::stack(const stack<T>& other) {
    _size = other._size;
    _end_idx = other._end_idx;
    _data = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

template <typename T>
stack<T>::~stack() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
    if (this == &other) return *this;
    delete[] _data;
    _data = nullptr;
    _size = other._size;
    _end_idx = other._end_idx;
    _data = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
    return *this;

}

template <typename T>
void stack<T>::push(const T& str) {
    if (_size == 0) {
        T* temp = new T[++_size];
        temp[++_end_idx] = str;
        delete[] _data;
        _data = temp;
        temp = nullptr;

    }
    else if (_size == _end_idx + 1) {
        T* temp = new T[_size * 2];
        for (size_t i = 0; i < _size; i++) {
            temp[i] = _data[i];
        }
        temp[++_end_idx] = str;
        delete[] _data;
        _data = temp;
        temp = nullptr;
        _size = _size * 2;
    } else {
        _data[++_end_idx] = str;
    }
}

template <typename T>
void stack<T>::pop() {
    _end_idx--;
    _size--;
}

template <typename T>
T stack<T>::top() {
    return _data[_end_idx];
}

template <typename T>
size_t stack<T>::size() {
    return _end_idx;
}

template <typename T>
bool stack<T>::is_empty() {
    return _end_idx == 0;
}


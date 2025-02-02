/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Your Name
 */

#include "stack-stage1.h"
#include <iostream>
#include <string>

using namespace std;

stack::stack() {
    // _data = string[4];
    // _data = new string[1];
    _data = new string[0];
    _size = 0;
    _end_idx = -1;
}

void stack::push(const string& str) {
    // _data[_size] = str;
    if (_size == 0) {
        string* temp = new string[++_size];
        temp[++_end_idx] = str;
        delete[] _data;
        _data = temp;
        temp = nullptr;

    }
    else if (_size == _end_idx + 1) {
        string* temp = new string[_size * 2];
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
        // _size++;
    }
}

void stack::pop() {
    if (!this->is_empty()) {
        _data[_end_idx--] = "";
        _size--;
    }
}

string stack::top() {
    if (!this->is_empty()) {
        return _data[_end_idx];
    } else {
        return "";
    }
}

size_t stack::size() {
    return _end_idx + 1;
}

bool stack::is_empty() {
    // cout << "Size: " << _size << endl;
    return _end_idx + 1 == 0;
}

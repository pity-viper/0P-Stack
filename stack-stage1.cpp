/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Your Name
 */

#include "stack-stage1.h"

using namespace std;

string stack::top() {
    return "Hello";
}

void stack::push(const string& str) {
    _data[_size] = str;
}

void stack::pop() {
    _data[--_size] = "";
}

string stack::top() {
    if (!this->is_empty()) {
        return _data[_size - 1];
    } else {
        return "";
    }
}

size_t stack::size() {
    return _size;
}

bool stack::is_empty() {
    return _size == 0;
}

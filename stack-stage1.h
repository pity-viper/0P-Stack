/*
 * stack-stage1.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead use the std:: prefix where required in class definitions, as
 * demonstrated below.
 */

class stack {
public:
    std::string top(); // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
    void push(const std::string &);// { return; }
    void pop();// { return; }
    size_t size();// { return 0; }
    bool is_empty();// { return true; }

    stack();// { ; }

private:
    std::string _data[4];
    size_t _size;
};

#endif

#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H
#include <memory>        // shared_ptr
#include <iostream>      // printf
#include <stack>         // stack
#include <vector>        // vector

// SetOfStacks Class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void push(int d)       --> Insert d onto the top of the stack
// int pop()              --> Delete the top value from the stack and return it
// in popAt(int i)        --> Pop a value from a specific substack
// *******************ERRORS*******************************
// NO ERRORS YET


template <class T>
class SetOfStacks { 
    private: 
        int stackMax = 4;
        int curr = -1;
        std::vector<std::stack<T>> allStacks;

    public: 
        SetOfStacks(int s);
        ~SetOfStacks();
        void push(T d);
        T pop();
        T popAt(int n);
};
#endif

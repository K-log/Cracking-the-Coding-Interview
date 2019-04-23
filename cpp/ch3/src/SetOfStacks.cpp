#include "SetOfStacks.h"
#include <stack>

template <class T>
SetOfStacks<T>::SetOfStacks(int s) {
   stackMax = s; 
   allStacks.push_back(std::stack<T>());
   curr = 0;
}

template <class T>
SetOfStacks<T>::~SetOfStacks() {
    allStacks.erase(allStacks.begin(), allStacks.end());
}


template <class T>
void SetOfStacks<T>::push(T d) {
    if(allStacks.size() < 1) {
        curr = 0;
        allStacks.push_back(std::stack<T>());
    }
    
    if(allStacks[curr].size() > stackMax-1) {
        curr++;
        allStacks.push_back(std::stack<T>());
    }
    

    allStacks[curr].push(d);
}


template <class T>
T SetOfStacks<T>::pop() {
    if(curr < 0) {
        throw "Unable to pop() from empty stack!";
    }
    
    T val = allStacks[curr].top();
    allStacks[curr].pop();

    if(allStacks[curr].size() < 1) {
        //std::cout << allStacks[curr].size() << '\n';
        allStacks.erase(allStacks.begin()+curr);
        curr--;
    }

    return val;
}


template <class T>
T SetOfStacks<T>::popAt(int n) { 
    if(curr < 0 || n > allStacks.size() || n < 0) {
        throw "Unable to pop() from empty stack!";
    }
   
    T val = allStacks[n].top();
    allStacks[curr].pop();

    if(allStacks[curr].size() < 1) {
        //std::cout << allStacks[curr].size() << '\n';
        allStacks.erase(allStacks.begin()+curr);
        curr--;
    }

    return val;
}

/**
 * 
 * CCI CH3.3 
 *
 * Noah
 *
 * Create a set of stacks where your data structures is a stack built out of multiple smaller stacks. Each smaller stack has a maximum size and when that size is reached a new stack is created. To the user the data structure should appear no different than a regular stack.
 *
 */
#include "SetOfStacks.cpp"


int main() {
    printf("Test out SetOfStacks\n");
    SetOfStacks<int> myStack(4);
    
    printf("Stack allocated\n");

    int i = 0;
    while(i < 20) {
        std::cout << i << '\n';
        myStack.push(i);
        i++;
    }
    
    printf("Stack filled\n");
    
    while(i > 0) {
        std::cout << myStack.pop() << std::endl; 
        i--;
    }
   
    return 1;
}

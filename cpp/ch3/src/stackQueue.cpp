/**
 * 
 * CCI CH2.3 
 *
 * Noah
 *
 * Implement a Queue using two stacks.
 *
 */


#include <stack>
#include <iostream>

template <class T>
class MyQueue {
    public:
        void add(T d) {
            while(queue.size() > 0) {
                tempStack.push(queue.top());
                queue.pop();
            }

            queue.push(d);

            while(tempStack.size() > 0) {
                queue.push(tempStack.top());
                tempStack.pop();
            }
        }

        void remove() { 
            return queue.pop(); 
        }

        T peek() { 
            return queue.top(); 
        }

        bool isEmpty() { 
            return queue.size() > 0; 
        }


    private:
        std::stack<T> queue;
        std::stack<T> tempStack;

};



int main() {
    printf("Testing MyQueue implemented with two stacks.\n");
    MyQueue<int> queue;

    int i = 0;
    while(i < 10) {
        queue.add(i);
        i++;
    }

    while(i > 0) {
        std::cout << queue.peek() << '\n';
        queue.remove();
        i--;
    }


    return 1;
}

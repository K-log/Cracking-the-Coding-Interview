#include "linkedList.h"


class LinkedList {
    public: 
        LinkedList(){}
        ~LinkedList();
        bool insertNode(int d, int index=len) {
            if(index > len || index < 0) {
                return false;
            }

            if(head == NULL || tail == NULL) {
                // Case for empty list.
                Node *newNode = new Node(d, NULL, NULL);
                head = newNode;
                tail = newNode;
                return true;
            }
            
            if(index/2 > len/2) {                 
                // Try and find the shortest way to get to the index.
                Node *in = getNodeReverse(index);
            } else {
                Node *in = getNodeForward(index);
            }

            Node *newNode = new Node(d, in.prev, in);
            in.prev = newNode;
            newNode.prev.next = newNode;

            return true;
        }
        bool deleteNode(int d);
        int length() {
            return len;
        }
        
    private: 
        Node *head = NULL;
        Node *tail = NULL;
        int len = 0;
        
        Node getNodeReverse(int index){
            // Get the node at index starting the search from the tail of the list.
            int currIndex = 0;
            Node currNode = tail;
            While(currIndex > index){
               currNode = currNode.prev;
               currIndex--;
            }    
            return currNode;
        }

        Node getNodeReverse(int index){ 
            // Get the node at the index starting the search from the head of the list.
            int currIndex = 0;
            Node currNode = head;
            While(currIndex < index){
               currNode = currNode.prev;
               currIndex++;
            } 
            
            return currNode;
        }

        class Node {
            Node *next;
            Node *prev;
            int data;
            Node(int d, Node *p, Node *n) {
                data = d;
                prev = p;
                next = n;
            }
        };
};





int main() {
    LinkedList lList;
    lList.insertNode(10, 0);
    lList.insertNode(4, 1);
    lList.insertNode(5, 1);
}

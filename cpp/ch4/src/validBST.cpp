/**
 *
 * CCI Ch4.5
 *
 * Noah 
 *
 * Check if a Binary tree is a valid binary search tree.
 *
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <memory>
using namespace std;

class Node {
    public:
        int data;
        shared_ptr<Node> left = nullptr;
        shared_ptr<Node> right = nullptr;
        Node(int d) {
            data = d;
        }
};


bool isValid(shared_ptr<Node> root) {
    if(root == nullptr) {
        return true;
    }

    shared_ptr<Node> left = root->left;
    shared_ptr<Node> right = root->right;

    if(left != nullptr){    
        if(!isValid(root->left)) {
            return false;
        }
    }

    if(right != nullptr){
        if(!isValid(root->right)) {
            return false;
        }
    }

    return true;
}

void printNodes(shared_ptr<Node> n) {
    if(n == nullptr) {
        return;
    }
   
    printNodes(n->left);
    printf("%d ", n->data);
    printNodes(n->right);
}


shared_ptr<Node> minTree(vector<int> arr, int start, int end) {
    if(end < start) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    shared_ptr<Node> root (new Node(arr[mid]));
    root->left = minTree(arr, start, mid-1);
    root->right = minTree(arr, mid+1, end);
    
    return root;
}


int main() {
    printf("Testing isValid.\n");
    vector<int> preTreeEven = {0,1,2,3,4,5,6,7,8};
    vector<int> preTreeOdd = {0,1,2,3,4,5};

    shared_ptr<Node> temp = minTree(preTreeEven, 0, preTreeEven.size()-1);
    printNodes(temp);
    printf("\n%s\n", isValid(temp) ? "True" : "False");
    printf("\n");
    temp = minTree(preTreeOdd, 0, preTreeOdd.size()-1);
    printNodes(temp);
    printf("\n%s\n", isValid(temp) ? "True" : "False");
    printf("\n");
    return 1;
}

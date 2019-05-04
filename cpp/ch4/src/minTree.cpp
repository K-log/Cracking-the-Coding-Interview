/**
 *
 * CCI Ch4.2
 *
 * Noah 
 *
 * Given a sorted array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <memory>
using namespace std;


vector<int> arrToTree2(vector<int> in) {
    printf("HERE1");
    if(in.size() < 3) {
        if(in[1] > in[0]) {
            return vector<int> {in[0], -1, in[1]};
        }
        return vector<int> {in[0], in[1], -1};
    }

    if(in.size() == 3) {
        return vector<int> {in[1], in[0], in[2]};
    }
    printf("HERE");

    int rootHalf = (int)floor(in.size()*0.5);
    int leftHalf = (int)floor(in.size()*0.75);
    int rightHalf = (int)floor(in.size()*0.25);
    int root = in[rootHalf];
    int left = in[leftHalf];
    int right = in[rightHalf];
 
    vector<int> leftLeftSub = arrToTree2(vector<int> (in.begin(), in.begin()+leftHalf));
    vector<int> leftRightSub = arrToTree2(vector<int> (in.begin()+leftHalf+1, in.begin()+rootHalf));
    vector<int> rightLeftSub = arrToTree2(vector<int> (in.begin()+rootHalf+1, in.begin()+rightHalf));
    vector<int> rightRightSub = arrToTree2(vector<int> (in.begin()+rightHalf+1, in.end()));

    printf("Root: %d\n", root);
    printf("Left: ");
    for(int i : leftLeftSub) {
        printf("%d ", i);
    }
    printf("\n%d\n", left);
    for(int i : leftLeftSub) {
        printf("%d ", i);
    }
    printf("\n");
 
    printf("Right: ");
    for(int i : rightLeftSub) {
        printf("%d ", i);
    }
    printf("\n%d\n", right);
    for(int i : rightRightSub) {
        printf("%d ", i);
    }
    printf("\n");

    vector<int> out = {root, left, right};
    out.insert(out.end(), leftLeftSub.begin(), leftLeftSub.end());
    out.insert(out.end(), leftRightSub.begin(), leftRightSub.end());
    out.insert(out.end(), rightLeftSub.begin(), rightLeftSub.end());
    out.insert(out.end(), rightRightSub.begin(), rightRightSub.end());

    printf("Full Tree: ");
    for(int i : out) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    return out;
}

vector<int> arrToTree(vector<int> arr) {
    
    if(arr.empty()) {
        //printf("No value left\n");
        vector<int> tree = {-1};
        return tree;
    }

    if(arr.size() == 2) {
        if(arr[0] > arr[1]) {
            return vector<int> {arr[0], -1, arr[1]};
        }
            return vector<int> {arr[0], arr[1], -1};
    }

    if(arr.size() == 3) {
        if(arr[0] > arr[1]) {
            swap(arr[0], arr[1]); 
        }
        return arr;
    }
 
    int half = (int)floor(arr.size()/2);

    vector<int> right = arrToTree(vector<int>(arr.begin()+half+1, arr.end())); // recursively construct the right subtree
    vector<int> left = arrToTree(vector<int>(arr.begin(), arr.begin()+half));  // recursively construct the left subtree
    
    printf("\nRoot: %d\n", arr[half]);
    printf("Left: ");
    for(int i : left){
       printf("%d ", i); 
    }

    printf("\nRight: ");
    for(int i : right){
       printf("%d ", i); 
    }

    vector<int> tree;                                       // Initialize the tree
    tree.reserve(left.size() + right.size() + 1);               // prealocate memory
    tree.push_back(arr[half]);                              // Insert the root val
    int count = left.size() > right.size() ? left.size() : right.size();
    int iter = 0;
    int level = 0;
    while(iter < count) {
        if(iter < left.size()) {
            for(int n = 0; n < level>>2; n++) {
                tree.push_back(left[0]);
                left.erase(left.begin());
            }
        }
        if(iter < right.size()) {
            for(int n = 0; n < level>>2; n++) {
                tree.push_back(right[0]);
                right.erase(right.begin());
            }
        }
        iter += level>>2;
        level++;
    }

    //tree.insert(tree.end(), left.begin(), left.end());      // Insert the left subtree
    //tree.insert(tree.end(), right.begin(), right.end());    // Insert the right subtree

    printf("\nFull Tree: ");
    for(int i : tree) {
        printf("%d ", i);
    }
    printf("\n");
    return tree; 
}

class Node {
    public:
        int data;
        shared_ptr<Node> left = nullptr;
        shared_ptr<Node> right = nullptr;
        Node(int d) {
            data = d;
        }
};


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


void printNodes(shared_ptr<Node> n) {
    if(n == nullptr) {
        return;
    }
   
    printNodes(n->left);
    printf("%d ", n->data);
    printNodes(n->right);
}

int main() {
    printf("Testing Int Array to Binary Tree.\n");
    vector<int> preTreeEven = {0,1,2,3,4,5,6};
    vector<int> preTreeOdd = {0,1,2,3,4,5};

    shared_ptr<Node> temp = minTree(preTreeEven, 0, preTreeEven.size()-1);
    printNodes(temp);
    printf("\n");
    temp = minTree(preTreeOdd, 0, preTreeOdd.size()-1);
    printNodes(temp);
    printf("\n");
    return 1;
}

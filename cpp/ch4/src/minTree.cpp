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

vector<int> arrToTree(int i, vector<int> arr) {
    
    if(arr.empty()) {
        //printf("No value left\n");
        vector<int> tree = {-1};
        return tree;
    }

    int half = (int)floor(arr.size()/2);

    if(arr.size() < 3) {
        //printf("Only 1 value left\n");
        if(arr.size() == 1) {
            return arr; 
        }
        if(arr[0] > arr[1]) {
            swap(arr[0], arr[1]); 
        }
        return arr;
    }
 
    vector<int> right = arrToTree(i+1, vector<int>(arr.begin()+half+1, arr.end())); // recursively construct the right subtree
    vector<int> left = arrToTree(i+2, vector<int>(arr.begin(), arr.begin()+half));  // recursively construct the left subtree
    
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
    tree.insert(tree.end(), left.begin(), left.end());      // Insert the left subtree
    tree.insert(tree.end(), right.begin(), right.end());    // Insert the right subtree

    printf("\nFull Tree: ");
    for(int i : tree) {
        printf("%d ", i);
    }
    printf("\n");
    return tree; 
}

int main() {
    printf("Testing Int Array to Binary Tree.\n");
    vector<int> preTreeEven = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    vector<int> preTreeOdd = {0,1,2,3,4,5,6,7,8,9,10,11,12};

    vector<int> test = arrToTree2(preTreeOdd);
    for(int i : preTreeOdd) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i : test) {
        printf("%d ", i);
    }
    printf("\n\n");
    printf("Even Tree\n");
    test = arrToTree2(preTreeEven);
    for(int i : preTreeEven) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i : test) {
        printf("%d ", i);
    }
    printf("\n\n");
    return 1;
}

/**
 *
 * CCI Ch4.3
 * 
 * Noah
 *
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth. d linked lists where d is the depth of the tree.
 *
 */


#include <vector>
#include <forward_list>
#include <iostream>
#include <cmath>
using namespace std;

//Start (2^i)-1
//End ((2^i)+((2^i)-i) - (2^i))

vector<forward_list<int>> listOfdepths(vector<int> tree) {
    vector<forward_list<int>> out;

    for(int i = 0; i < tree.size(); i++) {
        int l = pow(2, i);
        int start = l-1;
        int end = l+start;
        if(tree.begin()+end > tree.end()) {
            return out;
        } 
        out.push_back(forward_list<int>(tree.begin()+start, tree.begin()+end));  
    }
    printf("\n");
    return out;
}

int main() {
    printf("Testing list of depths.\n");
    vector<int> test = {3, 1, 5, 0, 2, 4, 6};
    for(forward_list<int> list : listOfdepths(test)) {
        for(int i : list) {
            printf("%d ", i);
        } 
        printf("\n");
    }

    test = {3, 1, 5, 0, 8, 2, 4, 6};
    for(forward_list<int> list : listOfdepths(test)) {
        for(int i : list) {
            printf("%d ", i);
        } 
        printf("\n");
    }
    return 1;
}

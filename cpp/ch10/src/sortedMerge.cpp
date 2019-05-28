/**
 *
 * CCI Ch10.1
 *
 * Given two sorted arrays A and B where A has enough empty space to hold B, merge B into A in sorted order.
 *
 * Noah
 */


/*
 * Cases:
 *
 * A+B is already in sorted order.
 *
 * B+A is already in sorted order.
 *
 * A+B is not in sorted order.
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Modified version of Quick Sort from the book
int partition(vector<int> vec, int left, int right) {
    int pivot = vec[(left+right)/2];
    while(left <= right) {

        while(vec[left] < pivot) left++;

        while(vec[right] > pivot) right--;

        if(left <= right) {
            swap(vec[left], vec[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quickSort(vector<int> vec, int left, int right) {
    int index = partition(vec, left,  right);
    if(left < index-1) {
        quickSort(vec, left, index-1);
    }

    if(index < right) {
        quickSort(vec, index, right);
    }
}

vector<int> sortedMerge(vector<int> a, vector<int> b) {
    // Note: This only works for comparable values 

    a.insert(a.end(), b.begin(), b.end()); // O(n)
    //quickSort(a, 0, a.size()-1); // O(n log n) -- Broken
    sort(a.begin(), a.end()); // O(n log n) 

    return a;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    a = sortedMerge(a, b);

    for(auto i : a) {
        printf("%d ", i);
    }
    printf("\n");

    b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    a = sortedMerge(a, b);

    for(auto i : a) {
        printf("%d ", i);
    }
    printf("\n");


    return 1;
}




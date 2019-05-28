/**
 *
 * CCI Ch10.3
 *
 * Given an array of integers sorted in increasing order that has also been rotated an unknown amount of times, find an element in the array.
 *
 * Noah
 */




#include <iostream>
#include <vector>
using namespace std;

int searchRotArr(vector<int> a, int val) {
    int i = 0;

    while(i < a.size()) {
        if(a[i] == val) {
            return i;
        }

        i++;
    }
    

    return -1;
}


int search(vector<int> arr, int l, int h, int key) 
{ 
    if (l > h) {
        return -1;
    }
  
    int mid = (l+h)/2; 
    if (arr[mid] == key) { 
        return mid;
    }
  
    if (arr[l] <= arr[mid]) { 
        if (key >= arr[l] && key <= arr[mid]) {
            return search(arr, l, mid-1, key); 
        }

        return search(arr, mid+1, h, key); 
    } 
  
    if (key >= arr[mid] && key <= arr[h]) {
        return search(arr, mid+1, h, key); 
    }
  
    return search(arr, l, mid-1, key); 
} 
  

int main() {
    vector<int> a = {15, 16, 17, 18, 1, 6, 7, 8, 9, 10, 12, 14};
    
    printf("%d\n", searchRotArr(a, 18));

    printf("%d\n", searchRotArr(a, 9));

    printf("%d\n", search(a, 0, a.size()-1, 18));

    return 1;
}

/**
 *
 * CCI Ch10.3
 *
 * Given a array of integers sorted in increasing order that has also been rotated an unknown amount of times, find an element in the array.
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


int main() {
    vector<int> a = {15, 16, 17, 18, 1, 6, 7, 8, 9, 10, 12, 14};
    
    printf("%d\n", searchRotArr(a, 18));

    printf("%d\n", searchRotArr(a, 9));

    return 1;
}

/**
 * CCI CH1.8
 *
 * Noah
 *
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
 *
 */


#include <iostream>
#include <vector>
#include <set>
using namespace std;

void ZeroMatrix(vector<vector<int>> arr){
    set<int> zeros; // Size n
    // O(n*m) or O(n^2)
    for(int i = 0; i != arr.size(); i++){
        for(int j = 0; j != arr[i].size(); j++){
            if(arr[i][j] == 0){
                zeros.insert(j); // O(log n) amortized O(1)
            }
        }
    }

    // O(n*m) or O(n^2)
    for(int i = 0; i != arr.size(); i++){
        for(int j = 0; j != arr[i].size(); j++){
            auto z = zeros.find(j); // O(log n)
            if(arr[i][j] == 0){
                vector<int> temp (arr[i].size(), 0); // Size n
                arr[i] = temp; // O(n)
                break;
            } else if(z != zeros.end()){
                arr[i][j] = 0; // O(1)
            
            }
        }
    }

    // This is only for print out the result
    for(int i = 0; i != arr.size(); i++){
        for(int j = 0; j != arr[i].size(); j++){
            cout << arr[i][j] << ' '; 
        }
        cout << '\n';
    }
}


void ZeroMatrixInPlace(vector<vector<int>> &arr){
    set<int> zeros;
    for(int i = 0; i != arr.size(); i++){
        for(int j = 0; j != arr[i].size(); j++){
            if(arr[i][j] == 0){
                zeros.insert(j);
            }
        }
    }
    for(int i = 0; i != arr.size(); i++){
        for(int j = 0; j != arr[i].size(); j++){
            auto z = zeros.find(j);
            if(arr[i][j] == 0){
                vector<int> temp (arr[i].size(), 0);
                arr[i] = temp;
                break;
            } else if(z != zeros.end()){
                arr[i][j] = 0;
            
            }
        }
    }

}


int main(){
    printf("Testing ZeroMatrix with one matrix\n");
    vector<vector<int>> test = {
        {1, 2, 3, 4, 0, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 0, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 0, 8, 9},
        {1, 2, 3, 4, 0, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}
    };
    ZeroMatrix(test);

    printf("\nTesting ZeroMatrixInPlace with one matrix\n");

    test = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    ZeroMatrixInPlace(test);

    // This is only for print out the result
    for(int i = 0; i != test.size(); i++){
        for(int j = 0; j != test[i].size(); j++){
            cout << test[i][j] << ' '; 
        }
        cout << '\n';
    }

    return 1;
}



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

    // This is only for print out the result
    for(int i = 0; i != arr.size(); i++){
        for(int j = 0; j != arr[i].size(); j++){
            cout << arr[i][j]; 
        }
        cout << '\n';
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

    return 1;
}



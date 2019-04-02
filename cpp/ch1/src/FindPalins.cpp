/**
 * CCI CH1.4
 *
 * Noah
 *
 * Given a string, find all permutations of it that are also palindromes.
 *
 */

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsPalin(string s){ 
    int j = s.size();
    if(j % 2 == 0){
        // Case for even strings
        cout << s.size() << '\n';
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[j]){
                return false;
            }
            j--;
        }
    } else {
        // Case for odd strings
        //cout << s.size() << '\n';
        for(int i = 0; i < j; i++){
            if(s[i] != s[j]){
                return false;
            }
            j--;
        }
    }
    return true;
}

void FindPalins(string s){
    sort(s.begin(), s.end());
    do {
        //cout << s << '\n';
        if(IsPalin(s)){
            cout << s << '\n';
        }

    } while(next_permutation(s.begin(), s.end())); 
}



int main(){
    printf("Running FindPalins with two strings.\n");
    string tests = "taco cat";
    printf("taco cat: \n");
    
    FindPalins(tests);
    //const char* t = IsPalin("abc cba") ? "true" : "false";
    //printf("IsPalin: %s\n", t);
    return 1; 
}

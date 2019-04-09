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
    // Remove whitespace
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    int j = s.size()-1;
    for(int i = 0; i < j; i++){
        if(s[i] != s[j]){
            return false;
        }
        j--;
    }
    return true;
}

void FindPalins(string s){
    sort(s.begin(), s.end());
    do {
        if(IsPalin(s)){
            cout << "True: ";
            cout << s << '\n';
        }

    } while(next_permutation(s.begin(), s.end())); 
}



int main(){
    printf("Running FindPalins with two strings.\n");
    string tests = "tact coa";
    printf("taco cat: \n");
    FindPalins(tests);

    tests = "abccba";
    printf("abccba: \n");
    FindPalins(tests);

    return 1; 
}

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
    int j = s.size();
    if(j % 2 == 0){
        // Case for even strings
        // TODO: Fix broken end case
        for(int i = 0; i < (s.size()/2); ++i){
            if(s[i] != s[j] && i < j){
                return false;
            }
            --j;
        }
    } else {
        j--;
        // Case for odd strings
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

    tests = "aab bcc";
    printf("aab bcc: \n");
    FindPalins(tests);

    /*
    const char* t = IsPalin("taco cat") ? "true" : "false";
    printf("IsPalin odd: %s\n", t);
    t = IsPalin("abccba") ? "true" : "false";
    printf("IsPalin even: %s\n", t);
    */
    return 1; 
}

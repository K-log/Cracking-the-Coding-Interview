/**
 * CCI Ch1.6
 *
 * Noah
 *
 * Compress a string by group runs of like elements into that element followed by a number representing the repetitions of that element.
 *
 */


#include <string>
#include <iostream>
using namespace std;

string StrCompr(string s){
    int start = 0;
    char c = s[0];
    for(int i = 0; i != s.size(); i++){
        if(c != s[i]){
            s.erase(start, i-start);
            s.insert(i, to_string(i-start));
            c = s[i];
            start = i;
        } else {
            c = s[i];
        }
    }

    return s;
}

int main(){
    printf("Testing StrCompr with two strings.\n");
    printf("aabcccccaaa -> %s\n", StrCompr("aabcccccaaa").c_str());
    printf("abc -> %s\n", StrCompr("abc").c_str());

    return 1;
}
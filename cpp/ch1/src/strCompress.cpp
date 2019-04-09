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

string StrCompress(string s){
    int start = 0;
    int i = 0;
    char c = s[0];
    string ret;
    for(i = 0; i < s.length(); i++){
        if(c != s[i]){
            ret.push_back(s[i-1]);
            ret.append(to_string(i-start));
            start = i;
            c = s[i];
        } 
    }
    ret.push_back(s[i-1]);
    ret.append(to_string(i-start));
    ret.push_back(s[i]);
    ret.append(to_string(i-start));

    return ret;
}


int main(){
    printf("Testing StrCompr with two strings.\n");
    printf("aabcccccaaa -> %s\n", StrCompress("aabcccccaaa").c_str());
    printf("abc -> %s\n", StrCompress("abc").c_str());
    printf("\" \" -> %s\n", StrCompress(" ").c_str());
    printf("ac -> %s\n", StrCompress("ac").c_str());
    return 1;
}

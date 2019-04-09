/**
 * CCI Ch1.9
 *
 * Noah
 *
 * Assuming you have a method isSubstring that checks 
 * if a string is a substring of another. 
 * Given two strings, determine if s2 is a 
 * rotation of s1 with only one call to isSubstring.
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isSubstring(string s1, string s2){ 
    return s1.find(s2, 0) ? true : false;
}

void RotString(string s1, string s2){    
    // Strin copies for printing the answer
    string ps1 = s1;
    string ps2 = s2;

    bool temp = isSubstring(s1, s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    printf("%s == %s: %s\n", ps1.c_str(), ps2.c_str(), (temp && s1==s2)? "true" : "false");
}


int main(){
    printf("Testing RotString with three strings.\n");
    RotString("waterbottle", "erbottlewat");
    RotString("programming", "ingprogramm");
    RotString("cake", "bake");
    return 1;
}

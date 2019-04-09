/**
 * CCI Ch1.5
 *
 * Noah
 *
 * Check if two string are one value away from each other.
 *
 */

#include <string>
#include <iostream>
#include <cmath>
using namespace std;


bool OneAway(string s1, string s2){
    if(s1.size()-s2.size() > 1 && s2.size()-s1.size() > 1){
        return false;
    }
    
    int c1 = 0;
    int c2 = 0;
    int err = 0;
    while(c1 < s1.size() && c2 < s2.size()){
        if(s1[c1] != s2[c2]){
            err++;
            if(s1.size() > s2.size()){
                c2++;
            } else if(s1.size() < s2.size()){
                c1++;
            }
        }
        c1++;
        c2++;
    }

    return err < 2 ? true : false;
}




int main(){
    printf("Testing OneAway with two strings\n");
    string tests = "ple"; 
    printf("Comparing: ple, pale = %s\n", (OneAway("pale", tests) ? "True" : "False"));
    tests = "bake";
    printf("Comparing: bake, pale = %s\n", (OneAway("pale", tests) ? "True" : "False"));
    return 1;

}

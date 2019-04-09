/**
 * CCI CH1.2
 *
 * Noah
 *
 * Check if two strings are permutations of each other.
 *
 */


#include <string>
#include <algorithm>
using namespace std;

bool CheckPerm(string s1, string s2){

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2 ? true : false;
}



int main(){

    printf("Testing CheckPerm with two strings.\n");
    const char* tests = CheckPerm("Test", "estT") ? "True" : "False";
    printf("Test == estT: %s\n", tests);
    tests = CheckPerm("Test", "test") ? "True" : "False";
    printf("Test == test: %s\n", tests);

    return 1;
}


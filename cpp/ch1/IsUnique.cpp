/**
 * CCI CH1.1
 * Noah
 *
 * Determine if a string contains all unique characters.
 *
 * Can this be done without an additional datastructure?
 */

#include <string.h>
#include <iostream.h>
using namespace std;

bool IsUnique(String s){
    
    for(int i = 0; i < s.size(); i++){
        j = 0;
        while(j < s.size()){
            if( j != i && s[j] == s[i]){
                return false;
            }
            j++;
        }
    }
    return true;
}


int main(){
    printf("Testing IsUnique without another datastructure.");
    String tests =  IsUnique("Test") ? "True" : "False"; 
    printf("Test = %s", tests);
    tests = IsUnique("Name") ? "True" : "False";
    printf("Name = %s", tests);

    return 1;
}

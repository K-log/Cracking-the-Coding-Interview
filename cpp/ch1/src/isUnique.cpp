/**
 * CCI CH1.1
 * Noah
 *
 * Determine if a string contains all unique characters.
 *
 * Can this be done without an additional datastructure?
 */

#include <string>
#include <set>
using namespace std;

bool IsUnique(string s){    
    if(s.size() > 128) { // If we use more than have the ascii character set then one value must have been repeated.
        return false;
    }


    for(int i = 0; i < s.size(); i++){ // O(n)
        int j = i+1;
        while(j < s.size()){           // O(n) 
            if(j != i && s[j] == s[i]){
                return false;
            }
            j++;
        }
    }
    return true;
}

bool IsUniqueDS(string s){
    set<char> temp (s.begin(), s.end()); //O(n)

    if(s.size() > temp.size()){
        return false;
    }
    return true;
}


int main(){
    printf("Testing IsUnique without another datastructure.\n");
    const char* tests =  IsUnique("Test") ? "True" : "False"; 
    printf("Test = %s\n", tests);
    tests =  IsUniqueDS("test") ? "True" : "False"; 
    printf("test = %s\n", tests);
    tests = IsUnique("Name") ? "True" : "False";
    printf("Name = %s\n\n", tests);

    
    printf("Testing IsUniqueDS with another datastructure.\n");
    tests =  IsUniqueDS("Test") ? "True" : "False"; 
    printf("Test = %s\n", tests);
    tests =  IsUniqueDS("test") ? "True" : "False"; 
    printf("test = %s\n", tests);
    tests = IsUniqueDS("Name") ? "True" : "False";
    printf("Name = %s\n", tests);

    return 1;
}

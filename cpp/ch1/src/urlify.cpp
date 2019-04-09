/**
 * CCI CH1.3
 *
 * Noah
 *
 * Convert all spaces in a string with %20.
 *
 */


#include <string>
#include <iostream>
using namespace std;


string Urlify(string s){ 
    string out; // Size n
    for(int i = 0; i != s.size(); i++){ // O(n)
        if(s[i] == ' '){ // O(1)
            out.push_back('%'); // O(1)
            out.push_back('2');
            out.push_back('0');
        } else {
            out.push_back(s[i]);
        }
    }
    return out;    
}




int main(){
    printf("Testing Urlify on two strings.\n");
    printf("The base string is: ");
    string s = "This is a test";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it;
    }
    printf("\nNow without spaces: ");
    string s2 = Urlify(s);
    for(auto it = s2.begin(); it != s2.end(); it++){
        cout << *it;
    }

    printf("\n\nThe second base string is: ");
    s = "Thisisatest";
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it;
    }
    printf("\nNow without spaces: ");
    s2 = Urlify(s);
    for(auto it = s2.begin(); it != s2.end(); it++){
        cout << *it;
    }


}

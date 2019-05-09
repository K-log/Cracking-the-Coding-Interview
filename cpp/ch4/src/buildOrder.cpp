/**
 *
 * CCI Ch4.7 
 *
 * Noah
 *
 * Given a list of projects and their dependencies as a pair. Write an algorithm to order the projects so their dependencies come before them in the build order. 
 *
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Topological sort
// Do some research
void createBuildOrder(vector<pair<char, char>> deps) {
   for(pair<char, char> i : deps) {
        
   } 


}


int main() {
    vector<pair<char, char>> deps = {
        pair<char,char> ('a', 'd'),
        pair<char,char> ('f', 'b'),
        pair<char,char> ('b', 'd'),
        pair<char,char> ('f', 'a'),
        pair<char,char> ('d', 'c')
    };
}

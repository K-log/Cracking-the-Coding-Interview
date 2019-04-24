/**
 * 
 * CCI CH3.6 
 *
 * Noah
 *
 * Question was real long and I dont have the energy to write it...
 *
 */

#include <list>
#include <iostream>
using namespace std;

class AnimShelter {
    public: 
        void enqueue(int d) {
            myList.push_back(d);
        }

        int dequeueAny() {
            if(myList.size() > 0) {
                int a = myList.front(); 
                myList.pop_front();
                return a;
            }
            return -1;
        }

        int dequeueDog() {        
            int a = -1;
            for(auto i = myList.begin(); i != myList.end(); i++) {
                if(*i == 0) {
                    a = *i; 
                    myList.erase(i); 
                    return a;
                } 
            }
            return a; 
        }

        int dequeueCat() { 
            int a = -1;
            for(auto i = myList.begin(); i != myList.end(); i++) {
                if(*i == 1) {
                    a = *i; 
                    myList.erase(i); 
                    return a;
                } 
            }
            return a; 
        }


    private:
        list<int> myList;
};


int main() {
    printf("Testing Animal shelter.\n");

    AnimShelter myShelter;

    myShelter.enqueue(0);   
    myShelter.enqueue(1);   
    myShelter.enqueue(0);   
    myShelter.enqueue(1);   
    myShelter.enqueue(0);   
    myShelter.enqueue(0);   
    myShelter.enqueue(1);   
    myShelter.enqueue(1);   
    myShelter.enqueue(0);   
    myShelter.enqueue(1);   

    cout << myShelter.dequeueAny() << '\n';
    cout << myShelter.dequeueCat() << '\n';
    cout << myShelter.dequeueDog() << '\n';

    return 1;
}


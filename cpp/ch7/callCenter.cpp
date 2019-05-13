/**
 *
 * CCI Ch7.2
 *
 * Call center with 3 levels. 
 * Call go to the first available person in the first level. 
 * If that person can't handle it it gets escalated up and 
 * the process repeats until either the call is over or 
 * it get to the highest level.
 */

#include<string>
using namespace std;


class Employee {
    public:
        Employee(string n) {
            string name = n;
        }
        ~Employee(){}


        void takeCall() {
            free = false;
        }

        bool isFree() {
            return free;
        }

        bool needsHelp() {
            return help;
        }

        void makeFree() {
            free = true;
        }

    private:
        string name = "";
        bool free = true;
        bool help = false;
    
};



class Respondent : public Employee {
    // There arent any new method for this class    
};

class Manager : public Employee {
    // There arent any new method for this class    
};

class Director : public Employee {
    // There arent any new method for this class    
};


void disbatchCall() {
    // Iterate through the list of Employees until one is found that is free
    // This would probably a method of a call center class

}

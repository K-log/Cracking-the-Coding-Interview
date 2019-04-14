/**
 *
 * CCI CH2.4
 *
 * Noah
 *
 * Given a partition value rearange the list so all values less than it are to the left and all values greater are to the right.
 *
 */

#include "LinkedList.h"

int main() { 
    printf("Testing Partition.\n");
    LinkedList lList(0);
    lList.insert(3);
    lList.insert(5);
    lList.insert(8);
    lList.insert(5);
    lList.insert(10);
    lList.insert(2);
    lList.insert(1);
    lList.insert(8);
    lList.insert(5);
    printf("Values in full list are: \n");
    lList.print();
    
    printf("Partition on 5: \n");
    lList.partition(5);
    lList.print();
    
    return 1;
}

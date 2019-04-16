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
    
    printf("PartitionStrict on 5: \n");
    lList.partitionStrict(5);
    lList.print();
    

    LinkedList sList(0);
    sList.insert(3);
    sList.insert(5);
    sList.insert(8);
    sList.insert(5);
    sList.insert(10);
    sList.insert(2);
    sList.insert(1);
    sList.insert(8);
    sList.insert(5);
    printf("Values in full list are: \n");
    sList.print();
    
    printf("Partition on 5: \n");
    sList.partition(5);
    sList.print();

    return 1;
}

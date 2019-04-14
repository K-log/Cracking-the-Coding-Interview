/**
 *
 * CCI CH2.1
 *
 * Noah
 *
 * Remove all the duplicates from an unsorted linked list.
 *
 */


#include "LinkedList.h"

int main() {
    printf("Testing Remove Duplicates.\n");
    LinkedList lList(0);
    lList.insert(1);
    lList.insert(1);
    lList.insert(3);
    lList.insert(5);
    lList.insert(5);
    lList.insert(6);
    lList.insert(7);
    lList.insert(9);
    lList.insert(9);
    printf("Values in full list are: \n");
    lList.print();

    printf("Removing duplicates: \n");
    lList.remDups();
    lList.print();

    return 1;
}

/**
 * 
 * CCI CH2.2 
 *
 * Noah
 *
 * Find the kth to last element in a singly linked list.
 *
 */

#include "LinkedList.h"

int main() {
    printf("Finding 3rd to last element in the list.\n");
    LinkedList lList(0);
    lList.insert(1);
    lList.insert(2);
    lList.insert(3);
    lList.insert(4);
    lList.insert(5);
    lList.insert(6);
    lList.insert(7);
    lList.insert(8);
    lList.insert(9);
    printf("Value in full list are: \n");
    lList.print();

    printf("Finding 3rd from the end: %d\n", lList.findK(3));
    printf("Fidning 0 from the end: %d\n", lList.findK(0));


    printf("Finding 3rd from the end with alt: %d\n", lList.findKalt(3));
    printf("Finding 0 from the end with alt: %d\n", lList.findKalt(0));

    return 1;
}

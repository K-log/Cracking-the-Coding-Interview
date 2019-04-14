/**
 * 
 * CCI CH2.3 
 *
 * Noah
 *
 * Delete a node in the middle of a list given only access to that node.
 *
 */


#include "LinkedList.h"

int main() { 
    printf("Testing Delete Middle Node.\n");
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
    printf("Values in full list are: \n");
    lList.print();

   printf("Delete 4\n");
   lList.delMid(4);
   lList.print();

   printf("Delete 6\n");
   lList.delMidD(6);
   lList.print();
   
   return 1;
}





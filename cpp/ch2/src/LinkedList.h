#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <memory>        // shared_ptr
#include <iostream>      // printf
#include <unordered_set> // set
#include <utility>       // pair 
#include <math.h>        // pow

// LinkedList Class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( d )               --> Insert int d at the end of the list
// void insert( n )               --> Insert node n at the end of the list
// void delete( d )               --> Remove int d 
// int length( )                  --> Return length of list
// void makeEmpty( )              --> Remove all list items
// void print ( )                 --> Print out the contents of the list
// int findK( k )                 --> Find the kth from the last element of the list
// int findKalt( k )              --> Find the kth from the last element of the list using length
// void delMid( d )               --> Delete d from the list if d is not the head or tail
// void delMidD( d )              --> Same as delMid except using the feature of a doubly linked list
// void partition( d )            --> Partion the list around d with all values greater or equal on the right and all values less than on the left
// std::shared_ptr<node> getStart --> Get a pointer to the start of the list
// int listToDigits()             --> Returns the list as a single digit
// int listToDigitsReverse()      --> Returns the list as a single digit in reverse
// void inToList()                --> Inserts a number with the digits in the correct order
// *******************ERRORS*******************************
// NO ERRORS YET
// *******************NOTES*******************************
// Should have added iterators........
// TODO: Add an iterator class



class LinkedList { 
    private: 
        struct node {
            int data;
            std::shared_ptr<node> next;
            std::shared_ptr<node> prev;
            node(int newData, std::shared_ptr<node> prevNode=nullptr, std::shared_ptr<node> nextNode=nullptr){
                data = newData;
                prev = prevNode;
                next = nextNode;
            }
            ~node(){}
        };
        std::shared_ptr<node> head = nullptr;
        std::shared_ptr<node> tail = nullptr;
        int len;

    public: 
        LinkedList();
        LinkedList(int d);
        ~LinkedList();
        void insert(int d);
        void insert(std::shared_ptr<node> n);
        void del(int d);
        void del(std::shared_ptr<node> n);
        std::shared_ptr<node> find(int d);
        void print();
        void remDups();
        int findK(int k);
        int findKalt(int k);
        int length();
        void delMid(int d);
        void delMidD(int d);
        void partition(int d);
        std::shared_ptr<node> getStart();
        int listToDigits();
        int listToDigitsReverse();
        void intToList(int d);

};
#endif

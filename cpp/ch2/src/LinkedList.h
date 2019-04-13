#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <memory>
#include <iostream>
#include <unordered_set>
#include <utility>

// LinkedList Class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )    --> Insert x, return True on success
// void delete( x )    --> Remove x, return True on success
// int length( )       --> Return length of list
// void makeEmpty( )   --> Remove all list items
// void print ( )      --> Print out the contents of the list
// int findK()         --> Find the kth from the last element of the list
// int findKalt()      --> Find the kth from the last element of the list using length
// *******************ERRORS*******************************
// NO ERRORS YET


class LinkedList { 
    public: 
        LinkedList(int d);
        ~LinkedList();
        void insert(int n);
        void del(int n);
        //void makeEmpty();
        void print();
        void remDups();
        int findK(int k);
        int findKalt(int k);
        int length();
       // void delMid(int d);


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
        //node getnodeReverse(int index);
        //node getnodeForward(int index);
};
#endif

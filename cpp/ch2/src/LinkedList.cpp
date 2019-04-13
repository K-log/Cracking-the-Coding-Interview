#include "LinkedList.h"

LinkedList::LinkedList(int d){
    std::shared_ptr<node> newNode(new node(d));
    head = newNode; 
    tail = newNode;
    len = 0;
}

LinkedList::~LinkedList(){
    std::shared_ptr<node> curr = head;
    while(curr != tail){
        head = nullptr;
        curr = curr->next;
        head = curr;
        len--;
    } 
}

void LinkedList::insert(int d) {
    std::shared_ptr<node> newNode(new node(d, tail)); 
    tail->next = newNode;
    tail = newNode;
    len++;
}

void LinkedList::del(int d) {
    if(len == 0) {
        std::fprintf(stderr, "List empty! Nothing to delete.\n");
        return;
    }     
    std::shared_ptr<node> curr = head;
    while(curr->data != d) {
        curr = curr->next;
        if(curr == tail && curr->data != d) {
            return;
        }
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    curr = nullptr; 

    len--;
}

void LinkedList::print() {
    std::shared_ptr<node> curr = head;
    int l = 0;
    while(curr != nullptr) {
        std::printf("Loc: %d -> %d\n", l, curr->data);
        curr = curr->next; 
        l++;
    }
}

int LinkedList::findK(int k) {
    std::shared_ptr<node> curr = head;
    int totalLen = 0;
    int l = 0;
    
    while(curr != nullptr) {
        curr = curr->next;
        totalLen++;
    }

    if(totalLen-k < 0) {
        return -1;
    }

    curr = head;
    while(curr != nullptr && l < totalLen-k){
        if(l == len-k){
            return curr->data;
        }
        curr = curr->next;
        l++;
    }

    return -1;
}


int LinkedList::findKalt(int k) {
    if(len-k < 0) {
        return -1;
    }
    std::shared_ptr<node> curr = head;
    int l = 0;
    while(curr != nullptr){
        if(l == len-k){
            return curr->data;
        }
        curr = curr->next;
        l++;
    }
    
    return -1;
}


int LinkedList::length() {
    return len;
} 

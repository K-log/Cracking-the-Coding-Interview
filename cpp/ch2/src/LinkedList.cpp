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
    // Linear time complexity, Constant space.
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
    // Linear time complexity, Constant space.
    std::shared_ptr<node> curr = head;
    int l = 0; 
    while(curr != nullptr) { // O(n)
        std::printf("Loc: %d -> %d\n", l, curr->data);
        curr = curr->next; 
        l++;
    }
}

void LinkedList::remDups() {
    // Linear time complexity (worst case quadratic), Linear space.
    std::unordered_set<int> allNodes;
    std::shared_ptr<node> curr = head;
    while(curr != tail) {
        printf("%d\n", curr->data);
        if(!std::get<1>(allNodes.insert(curr->data))){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if(tail == curr){
                tail = curr->prev;
            }
        }
        curr = curr->next;
    }
    
    if(!std::get<1>(allNodes.insert(curr->data))){
        curr->prev->next = nullptr;
        if(tail == curr){
            tail = curr->prev;
        }
    }
}

int LinkedList::findK(int k) {
    // Quadratic time complexity, Constant space.
    std::shared_ptr<node> curr = head; // O(1)
    int totalLen = 0; // O(1)
    int l = 0;        // O(1)
    
    while(curr != nullptr) { // O(n)
        curr = curr->next;
        totalLen++;
    }

    if(totalLen-k < 0) {
        return -1;
    }

    curr = head;
    while(curr != nullptr && l < totalLen-k){ // O(n)
        if(l == len-k){
            return curr->data;
        }
        curr = curr->next;
        l++;
    }

    return -1;
}


int LinkedList::findKalt(int k) {
    // Linear time complexity, Constant space.
    if(len-k < 0) {
        return -1;
    }
    std::shared_ptr<node> curr = head; // Size O(1)
    int l = 0; // Size O(1)
    while(curr != nullptr){ // O(n)
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

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

void LinkedList::insert(std::shared_ptr<node> n) {
    tail->next = n;
    n->prev = tail;
    n->next = nullptr;
    tail = n;

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

void LinkedList::del(std::shared_ptr<node> n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
}



std::shared_ptr<LinkedList::node> LinkedList::find(int d) { 
    // Returns either a pointer to node d or nullptr
    std::shared_ptr<node> curr = head;
    while(curr->data != d && curr != tail) {
        curr = curr->next;
    }
    return curr;
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
    std::printf("\n");
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
    // Catch the last element and a void a seg fault 
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

void LinkedList::delMid(int d){
    // Asside from getting pointer to the node this is linear time complexity
    std::shared_ptr<node> n = find(d); // O(n)
    if(n == head || n == tail){
        return;
    }
    std::shared_ptr<node> curr = head; 
    while(curr->next != n) { // O(n)
        curr = curr->next;
    }

    curr->next = n->next;
}


void LinkedList::delMidD(int d){
    // Asside from getting pointer to the node this is constant time complexity
    std::shared_ptr<node> n = find(d); // O(n)
    if(n == head || n == tail){
        return;
    } 
    n->next->prev = n->prev;
    n->prev->next = n->next;
}

void LinkedList::swap(std::shared_ptr<node> n1, std::shared_ptr<node> n2) {
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

void LinkedList::partition(int d) {
    std::shared_ptr<node> curr = head;    
    std::shared_ptr<node> end = tail;    
    std::shared_ptr<node> temp; 

    while(curr != end) {
        printf("%d-", curr->data);
        if(curr->data > d){
            printf("HERE");
            temp = curr;
            printf("HERE");
            del(curr);        // O(1)
            printf("HERE\n");
            insert(temp->data); // O(1)
            curr = temp->next;
        } else { 
            curr = curr->next;
        }
    } 
} 

#include "LinkedList.h"


LinkedList::LinkedList(){
    printf("Init new list\n");
    len = 0;
}

LinkedList::LinkedList(int d){
    std::shared_ptr<node> newNode(new node(d));
    head = newNode; 
    tail = newNode;
    len = 1;
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
    if(tail == nullptr || head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
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
        std::printf("Index: %d -> %d\n", l, curr->data);
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
        if(l == len-k-1){
            return curr->data;
        }
        curr = curr->next;
        l++;
    }

    return -1;
}


int LinkedList::findKalt(int k) {
    // Linear time complexity, Constant space.
    if(len-k-1 < 0) {
        return -1;
    }
    std::shared_ptr<node> curr = head; // Size O(1)
    int l = 0; // Size O(1)
    while(curr != nullptr){ // O(n)
        if(l == len-k-1){
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

void LinkedList::partition(int d) {
    // Quadratic time complexity and constant space
    std::shared_ptr<node> curr = head;    
    std::shared_ptr<node> end = tail;    
    std::shared_ptr<node> bubbleTemp = head;
    std::shared_ptr<node> part = curr;
    int temp;
    bool found = false;

    while(curr != end) {  // O(n^2) 
        if(curr->data == d && !found) {
            part = curr;
            found = true;
        } else if(curr->data >= d) {
            bubbleTemp = curr;
            while(bubbleTemp->data >= d && bubbleTemp != end) { // O(n)
                bubbleTemp = bubbleTemp->next;
            }  
            if(bubbleTemp != end){
                temp = bubbleTemp->data;
                bubbleTemp->data = curr->data;
                curr->data = temp;
            }
        }
        curr = curr->next;
    } 
    curr = part->next;
    while(curr->data < d) { // O(n)
        temp = part->data;
        part->data = curr->data;
        curr->data = temp;
        part = curr;
        curr = curr->next;
    } 
    printf("Partition complete!\n");
} 

std::shared_ptr<LinkedList::node> LinkedList::getStart() {
    return head;
}

int LinkedList::listToDigitsReverse() {
    // Linear time complexity and constant space.
    std::shared_ptr<node> curr = head;
    int num = 0;
    int count = 0;
    while(curr != nullptr) { // O(n)
        num += (curr->data * std::pow(10, count));
        //printf("%f\n", std::pow(10, count));
        count++;
        curr = curr->next; 
    }
    return num;
}


int LinkedList::listToDigits() {
    // Linear time complexity and constant space.
    std::shared_ptr<node> curr = head;
    int num = 0;
    int count = len-1;
    while(curr != nullptr) { // O(n)
        num += (curr->data * std::pow(10, count));
        //printf("%f\n", std::pow(10, count));
        count--;
        curr = curr->next; 
    }    
    return num;
}

void LinkedList::intToList(int d) { 
    // Linear time complexity.
    // Insert a number into a list with the digits in the correct order.
    if(d < 0) {
        d = -1*d;
    }
    if(d/10 > 0) {
        intToList(d/10);
    }
    insert(d%10);
}

bool LinkedList::isPalin() {
    std::shared_ptr<node> fst = head; 
    std::shared_ptr<node> snd = head;
    int halfLen = (len%2==0 ? len/2 : (len-1)/2)-1;
    int count = halfLen;
    int tempL = (len%2==0 ? halfLen : ((len)/2)+1);
    int index = 0;
    int arr[halfLen];
    while(count > -1 && index < len) {
        if(index > tempL) {
            arr[count] = snd->data;
            printf("%d[%d]\n", arr[count], count);
            count--;
        }
        index++;
        snd = snd->next;
    } 
    
    index = 0;
    while(index < halfLen) {
        printf("%d == %d[%d]\n", fst->data, arr[index], index); 
        if(fst->data != arr[index]){
            return false;
        } 
        fst = fst->next;
        index++;
    }
    return true;
} 


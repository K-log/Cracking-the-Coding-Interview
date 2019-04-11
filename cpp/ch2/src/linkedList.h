class LinkedList {
    public: 
        LinkedList();
        ~LinkedList();
        bool insertNode(int n, int index);
        bool deleteNode(int n);
        int length();
        
    private: 
        Node *head;
        Node *tail;
        int len;
        Node getNodeReverse(int index);
        Node getNodeReverse(int index);
    
        class Node {
            Node *next;
            Node *prev;
            int data;
            Node(); 
        };
};

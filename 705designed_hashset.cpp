#include <iostream>
using namespace std;
class Node{
public:
    Node(int _val):  val(_val), next(NULL){};
    int val;
    Node* next;
};
class MyHashSet {
public:
    friend class Node;
    MyHashSet() {
        
    }
    
    void add(int key) {
        Node* cur;
        if(head == NULL){
            cur = new Node(key);
            head = cur;
        }
        else{
            cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = new Node(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            while(head->val == key)    head = head->next;
            Node* cur = head;
            while(cur->next != NULL){
                if(cur->next->val == key){
                    cur->next = cur->next->next;
                    continue;
                }
                cur = cur->next;
            }
        }
    }
    
    bool contains(int key) {
        Node* cur = head;
        while(cur != NULL){
            if(cur->val == key)    return true;
            cur = cur->next;
        }
        return false;
    }
private:
    Node* head = NULL;
};
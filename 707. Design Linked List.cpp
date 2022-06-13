#include <iostream>
using namespace std;

class Node{

public:
    Node(): next(NULL){};
    Node(int value): val(value), next(NULL){};
    
    int val;
    Node* next;
};
class MyLinkedList {
public:
    friend class Node;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(head == NULL)    return -1;
        if(index > total)    return -1;
        int count = 0;
        cur = head;
        while(cur->next != NULL){
            if(count == index)    return cur->val;
            count++;
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        total++;
        if(head == NULL)    head = new Node(val);
        else{
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
        }
    }
    
    void addAtTail(int val) {
        total++;
        if(head == NULL)    head = new Node(val);
        else{
            Node* temp = new Node(val);
            cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = temp;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index > total+1)    return;              //遠超出來
        total++;
        if(index == 0){
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
            return;
        }
        int count = 0;
        cur = head;
        while(cur != NULL){
            if(count == index-1){
                Node* temp = new Node(val);
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
            count++;
            cur = cur->next;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index > total)    return;
        total--;
        if(index == 0){
            head = head->next;
            return;
        }
        int count = 0;
        cur = head;
        while(cur->next != NULL){
            if(count == index-1){
                cur->next = cur->next->next;
                break;
            }
            count++;
            cur = cur->next;
        }
        
    }
private:
    Node* head = NULL;
    Node* cur = NULL;
    int total = -1;                                 //因為第一個算0
};
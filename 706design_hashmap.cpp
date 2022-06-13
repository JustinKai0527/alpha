#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int val;
    int key;
    Node* next;
};
class MyHashMap {
public:
    MyHashMap() {

    }
    
    void put(int key, int value) {
        if(head == NULL){
            head = new Node;
            head->val = value;
            head->key = key;
        }    
        else{
            bool f = false;
            Node* cur = head;
            while(cur->next != NULL){
                if(cur->key == key){
                    cur->val = value;
                    f = true;
                    break;
                }
                cur = cur->next;
            }
            if(cur->key == key){
                cur->val = value;
                f = true;
            }
            if(!f){
                Node* temp = new Node;
                temp->val = value;
                temp->key = key;
                cur->next = temp;
                temp->next = NULL;
            }
        }
    }
    
    int get(int key) {
        Node* cur = head;
        while(cur != NULL){
            if(cur->key == key){
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(head != NULL){
            if(head->key == key)    head = head->next;
            Node* cur = head;
            if(cur != NULL){
                while(cur->next != NULL){
                    if(cur->next->key == key){
                        cur->next = cur->next->next;
                        break;
                    }
                    cur = cur->next;
                }
            }
        }
    }
private:
    Node* head = NULL;

};
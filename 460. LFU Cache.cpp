#include <iostream>
using namespace std;

class Node{
public:
    Node(){
        value = -1;
        count = -1;
        key = -1;
        next = NULL;
    };
    Node(int _key,int _value): key(_key), value(_value), next(NULL){};
    int count;
    int value;
    int key;
    Node* next;
};

class LFUCache {
public:
    friend class Node;
    LFUCache(int capacity) {
        if(capacity != 0){
            head = new Node();
            capacity--;
            cur = head;
            while(capacity != 0){
                Node* temp = new Node();
                cur->next = temp;
                cur = temp;
                capacity--;
            }
            end = cur;
        }
    }
    
    int get(int key) {
        if(head == NULL)    return -1;               //capacity = 0
        cur = head;
        if(head->key == key){
            head->count++;
            return head->value;
        }
        while(cur->next != NULL){
            if(cur->next->key == key){
                Node* temp = cur->next;
                cur->next = cur->next->next;
                temp->count++;
                temp->next = head;
                head = temp;
                if(end == temp)    end = cur;
                return head->value;
            }
            cur = cur->next;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(head == NULL)    return;                 //capacity = 0
        cur = head;
        if(head->count == -1){
            head->count = 1;
            head->key = key;
            head->value = value;
        }
        else{
            if(head->key == key){
                head->count++;
                head->value = value;
                return;
            }
            if(end->count == -1){
                while(cur->next != NULL){
                    if(cur->next->key == key){
                        cur->next->count++;
                        cur->next->value = value;
                        
                        Node* temp = cur->next;
                        cur->next = cur->next->next;
                        temp->next = head;
                        head = temp;
                        if(temp == end)    end = cur; 
                        break;
                    }
                    if(cur->next->count == -1){
                        cur->next->key = key;
                        cur->next->count = 1;
                        cur->next->value = value;

                        Node* temp = cur->next;
                        cur->next = cur->next->next;
                        temp->next = head;
                        head = temp;
                        if(temp == end)    end = cur;
                        break;
                    }
                    cur = cur->next;
                }
            }
            else{                               //LFU maybe arise
                bool f = false;
                while(cur->next != NULL){
                    if(cur->next->key == key){
                        cur->next->count++;
                        cur->next->value = value;
                        
                        Node* temp = cur->next;
                        cur->next = cur->next->next;
                        temp->next = head;
                        head = temp;
                        if(temp == end)    end = cur;
                        f = true; 
                        break;
                    }
                    cur = cur->next;
                }
                if(!f){
                    Node* special = NULL;
                    cur = head;
                    LFU = head;
                    LFU_total = 0;
                    while(cur->next != NULL){
                        if(LFU->count == cur->next->count){
                            if(LFU == cur)    LFU_total = 1;
                            special = cur;
                            LFU_total++;
                            LFU = cur->next;                    //偏後面
                        }
                        if(LFU->count > cur->next->count){
                            special = cur;
                            LFU_total = 1;
                            LFU = cur->next;
                        }
                        cur = cur->next;
                    }
                    if(LFU_total > 1){
                        LFU->count = 1;
                        LFU->key = key;
                        LFU->value = value;

                        special->next = special->next->next;
                        LFU->next = head;
                        head = LFU;
                        if(LFU == end)    end = special;
                    }
                    else if(LFU_total == 1){
                        LFU->key = key;
                        LFU->count = 1;
                        LFU->value = value;
                        
                        special->next = special->next->next;
                        LFU->next = head;
                        head = LFU;
                        if(LFU == end)    end = special;
                    }
                    else if(LFU == head){
                        head->count = 1;
                        head->key = key;
                        head->value = value;
                    }
                }
            }
        }
    }
private:
    Node* head = NULL;
    Node* end = NULL;
    Node* cur = NULL;
    Node* LFU = NULL;
    int LFU_total = 0;
};

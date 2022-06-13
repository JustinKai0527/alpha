#include <iostream>
using namespace std;

class Node{
public:
    Node(string _str):  str(_str),next(NULL),count(1){};
    int count;
    string str;
    Node* next;
};
class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(head == NULL){
            head = new Node(key);
            ansMax = head;
            ansMin = head;
        }
        else{
            Node* cur = head;
            bool f = false;
            if(head->str == key){
                head->count++;
                
                if(head->next != NULL){     //至少有兩個
                    if(ansMax->count < head->count){
                        ansMax2 = ansMax;
                        ansMax = head;
                    }
                    if(ansMin == head){
                        if(ansMin->count > ansMin2->count){
                            Node* temp = ansMin;
                            ansMin = ansMin2;
                            ansMin2 = temp;
                        }
                    }
                }
                f = true;
            }
            else{                           //至少有一個
                while(cur->next != NULL){
                    if(cur->next->str == key){
                        cur->next->count++;
                        if(ansMax->count <= cur->next->count){
                            if(ansMax != cur->next){
                                ansMax2 = ansMax;
                                ansMax = cur->next;
                            }
                        }

                        if(ansMin == cur->next){
                            if(ansMin2->count < ansMin->count){
                                ansMin = ansMin2;
                                ansMin2 = cur->next;
                            }
                        }
                        f = true;
                        break;
                    }
                    cur = cur->next;
                }
            }    
            
            if(!f){
                Node* temp = new Node(key);
                while(cur->next != NULL){
                    cur = cur->next;
                }
                cur->next = temp;
                
                if(ansMax2 == NULL)    ansMax2 = temp;
                if(ansMin->count >= temp->count){
                    ansMin2 = ansMin;
                    ansMin = temp;
                }  
            }
        }
    }
    
    void dec(string key) {
        if(head->next == NULL){
            head->count--;
            if(head->count == 0){
                ansMax = NULL;
                ansMin = NULL;
                head = NULL;
            }
        }
        bool Max = false;
        bool Min = false;
        if(head->str == key){
            Node* prev = NULL;
            Node* dectect = head;
            head->count--;
            
            if(ansMin->count > head->count && head->count != 0){
                if(ansMin != head){
                    Node* temp = ansMin;
                    ansMin = head;
                    ansMin2 = temp;
                }
            }
            if(head->count == 0){
                prev = head;
                head = head->next; 
            }
            if(prev == ansMin2){
                while(ansMin2->next != NULL){
                    if(prev == ansMin)    continue;
                    if(ansMin2->count > ansMin2->next->count)    ansMin2 = ansMin2->next;
                }
            }
            if(ansMax == prev){
                ansMin = head;
                if(head->next != NULL)    ansMin2 = head->next;
            }
            if(ansMax2 == prev){
                if(ansMin == head)    ansMax2 = head->next;
                else    ansMax2 = head;
            }
            if(ansMax == dectect){
                if(ansMax2->count > ansMax->count){
                    ansMax = ansMax2;
                    ansMax2 = dectect;
                }
            }
            if(ansMax2 == dectect){
                while(dectect->next != NULL){
                    if(ansMax == dectect)    continue;
                    if(ansMax2->count < dectect->next->count)    ansMax2 = dectect->next;
                    dectect = dectect->next;
                }
            }
        }
        else{
            Node* cur = head;
            while(cur->next != NULL){
                if(cur->next->str == key){
                    cur->next->count--;
                    Node* prev = NULL;
                    Node* dectect = cur->next;
                    if(ansMin->count > cur->next->count && cur->next->count != 0){
                        if(ansMin != cur->next){
                            Node* temp = ansMin;
                            ansMin = head;
                            ansMin2 = temp;
                        }
                    }
                    if(cur->next->count == 0){
                        prev = cur->next;
                        cur->next = cur->next->next; 
                    }
                    if(prev == ansMin2){
                        while(ansMin2->next != NULL){
                            if(prev == ansMin)    continue;
                            if(ansMin2->count > ansMin2->next->count)    ansMin2 = ansMin2->next;
                        }
                    }
                    if(ansMax == prev){
                        ansMin = cur->next;
                        if(cur->next->next != NULL)    ansMin2 = cur->next->next;
                    }
                    if(ansMax2 == prev){
                        if(ansMin == cur->next)    ansMax2 = cur->next->next;
                        else    ansMax2 = cur->next;
                    }
                    if(ansMax == dectect){
                        if(ansMax2->count > ansMax->count){
                            ansMax = ansMax2;
                            ansMax2 = dectect;
                        }
                    }
                    if(ansMax2 == dectect){
                        while(dectect->next != NULL){
                            if(ansMax == dectect)    continue;
                            if(ansMax2->count < dectect->next->count)    ansMax2 = dectect->next;
                            dectect = dectect->next;
                        }
                    }
                }
                cur = cur->next;
            }
        }
        if(head->next == NULL){
            ansMax = head;
            ansMin = head;
            ansMax2 = NULL;
            ansMin2 = NULL;
        }
    }
    
    string getMaxKey() {
        if(ansMax == NULL && head == NULL)     return "";
        if(ansMax == NULL)    ansMax = this->getMax();
        return ansMax->str;
    }
    
    Node* getMax() {
        if(head == NULL)    return NULL;
        Node* cur = head;
        if(ansMax == NULL)    ansMax = head;
        while(cur->next != NULL){
            if(ansMax->count < cur->next->count)    ansMax = cur->next;
            cur = cur->next;
        }
        if(ansMax->count < cur->count)    ansMax = cur;
        return ansMax;
    }
    string getMinKey() {
        if(ansMin == NULL && head == NULL)     return "";
        if(ansMin == NULL)    ansMin = this->getMin();
        return ansMin->str;
    }

    Node* getMin() {
        if(head == NULL)    return NULL;
        Node* cur = head;
        if(ansMin == NULL)    ansMin = head;
        while(cur->next != NULL){
            if(ansMin->count > cur->next->count)    ansMin = cur->next;
            cur = cur->next;
        }
        if(ansMin->count > cur->count)    ansMin = cur;
        return ansMin;
    }
private:
    Node* head = NULL;
    Node* ansMin = NULL;
    Node* ansMax = NULL;
    Node* ansMin2 = NULL;
    Node* ansMax2 = NULL;
};



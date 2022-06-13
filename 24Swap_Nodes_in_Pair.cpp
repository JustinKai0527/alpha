#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)    return head;
        ListNode* cur = head;
        int sum = 0;

        if(cur->next == NULL)   return head;
        ListNode* temp_fin = cur->next->next;
        ListNode* temp_mid = cur->next;
        temp_mid->next = cur;
        cur->next = temp_fin;
        cur = temp_fin;
        head = temp_mid;
        ListNode* prev = temp_mid->next;
        sum++;

        if(cur == NULL)    return head;
        while(true){
            if(cur->next == NULL)   break;
            temp_fin = cur->next->next;
            temp_mid = cur->next;
            temp_mid->next = cur;
            cur->next = temp_fin;
            cur = temp_mid;
            prev->next = cur;
            prev = cur->next;
            cur = cur->next->next;
            sum++;
            if(cur == NULL)    break;
        }
        return head;
    }
};

class Solution {
public:
    void swap(ListNode* cur, ListNode* prev){
        if(cur->next == NULL)  return;

        ListNode* temp = cur->next;
        ListNode* Next = cur->next->next;
        if(prev == NULL){
            cur->next = Next;
            temp->next = cur;
            replace = temp;
            swap(Next,cur);
        }
        prev->next = temp;
        temp->next = cur;
        cur->next = Next;

        swap(Next,cur);        
    }
    ListNode* swapPairs(ListNode* head) {
        swap(head,NULL);
        return replace;
    }
private: 
    ListNode* replace;
};
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)    return head;
        ListNode* reg = head;
        ListNode* cur = head;
        while(cur->next != NULL){                           //想法是往前插
            ListNode* temp = new ListNode;
            temp->val = cur->val;
            temp->next = head;
            head = temp;
            cur = cur->next;
        }
        ListNode* temp = new ListNode;
        temp->val = cur->val;
        temp->next = head;
        head = temp;
        
        cur = head;                                         //然後這邊是刪掉之前的Node;
        while(cur->next != reg){
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
};
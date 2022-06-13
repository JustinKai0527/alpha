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
    int pairSum(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while(cur->next != NULL){
            count++;
            cur = cur->next;
        }
        count++;
        count /= 2;                             //折半

        ListNode* prev = new ListNode;
        ListNode* Next = head->next;
        cur = head;
        while(count != 0){
            count--;
            cur->next = prev;
            prev = cur;
            cur = Next;
            Next = cur->next;
        }
        ListNode* twin_head = prev;
        head = cur;

        int max = 0;
        while(cur != NULL){
            if(max < cur->val+twin_head->val){
                max = cur->val+twin_head->val;
            }
            cur = cur->next;
            twin_head = twin_head->next;
        }
        return max;
        
    }
};
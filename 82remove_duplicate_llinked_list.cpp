#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

                                                                    // correct answer 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)  return NULL;
        ListNode* cur = head;
        ListNode* ans = head;
        ListNode* record = NULL;
        int special;
        bool f = false;
        while(cur->next != NULL){
            
            if(cur->val != cur->next->val  && !f){
                cout<<cur->val;
                ans->val = cur->val;
                record = ans;
                ans = ans->next;
                f = false;
            }
            else if(cur->val != cur->next->val)  f = false;
            else    f = true;
            special = cur->val;
            cur = cur->next;
        }
        if(cur->val != special){
            ans->val = cur->val;
            record = ans;
        }
        if(record == NULL)  return NULL;
        record->next = NULL;

        return head;
    }
};
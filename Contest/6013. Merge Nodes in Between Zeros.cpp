#include <iostream>
#include <vector>
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        head = head->next;
        ListNode* cur = head;
        
        while(cur->next != NULL){
            if(cur->next->val == 0){
                if(cur->next->next == NULL){
                    cur->next = cur->next->next;
                    break;
                }
                cur->next->val = cur->next->next->val;
                cur->next->next = cur->next->next->next;
            }
            else{
                cur->val+=cur->next->val;
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        else if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        int total1 = 0, total2 = 0;
        
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;

        ListNode* cur;
        ListNode* carry_out;
        ListNode* ans;
        ListNode* re_cur;
        while(l1->next != NULL){
            l1 = l1->next;
            total1++;
        }
        total1++;
        while(l2->next != NULL){
            l2 = l2->next;
            total2++;
        }
        total2++;
        if(total1>=total2){
            cur = cur1;
            ans = cur1;
            re_cur = cur2;
        }
        else if(total1<total2){
            cur = cur2;
            ans = cur2;
            re_cur = cur1;
        }

        while(cur->next != NULL){
            if(re_cur != NULL){
                cur->val += re_cur->val;
                re_cur = re_cur->next;
            }
            if(cur->val >= 10){
                cur->val %= 10;
                cur->next->val += 1;
            }
            cur = cur->next;
        }
        if(re_cur != NULL){
            cur->val += re_cur->val;
        }
        if(cur->val>=10){
            carry_out = new ListNode(1);
            cur->val %= 10;
            cur->next = carry_out;
        }
        return ans;
    }
};
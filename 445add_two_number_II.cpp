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
        else if(l2->val == 0){
            return l1;
        }
        else if(l1->val == 0){
            return l2;
        }
        int total1 = 0, total2 = 0;
        
        ListNode* cur1 = l1;
        ListNode* prev1 = l1;
        ListNode* Next1 = l1->next;
        ListNode* cur2 = l2;
        ListNode* prev2 = l2;
        ListNode* Next2 = l2->next;
        if(Next1 != NULL){
            while(cur1->next != NULL){
                if(total1 == 0){
                    prev1->next = NULL;
                    cur1 = Next1;
                    Next1 = Next1->next;
                }
                else{
                    cur1->next = prev1;
                    prev1 = cur1;
                    cur1 = Next1;
                    Next1 = Next1->next;
                }
                total1++;
            }
            total1++;
            cur1->next = prev1;
            prev1 = cur1;                                           //reverse 一波
        }
        else    total1++;
        if(Next2 != NULL){
            while(cur2->next != NULL){
                if(total2 == 0){
                    prev2->next = NULL;
                    cur2 = Next2;
                    Next2 = Next2->next;
                }
                else{
                    cur2->next = prev2;
                    prev2 = cur2;
                    cur2 = Next2;
                    Next2 = Next2->next;
                }
                total2++;
            }
            total2++;
            cur2->next = prev2;
            prev2 = cur2;                                           //reverse 一波
        }
        else    total2++;
        ListNode* cur;
        ListNode* carry_out;
        ListNode* ans;
        ListNode* re_cur;
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

        total1 = 0;
        cur1 = ans;
        prev1 = ans;
        Next1 = ans->next;
        if(Next1 != NULL){
            while(cur1->next != NULL){
                if(total1 == 0){
                    prev1->next = NULL;
                    cur1 = Next1;
                    Next1 = Next1->next;
                }
                else{
                    cur1->next = prev1;
                    prev1 = cur1;
                    cur1 = Next1;
                    Next1 = Next1->next;
                }
                total1++;
            }
            total1++;
            cur1->next = prev1;
            prev1 = cur1;                                           //reverse 一波
            ans = cur1;
        }
        return ans;
    }
};
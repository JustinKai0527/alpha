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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)    return head;
        ListNode* cur = head;
        int count = 0;
        while(cur->next != NULL){
            if(cur->next->val < cur->val){
                ListNode* temp = cur->next;
                ListNode* check = head;
                cur->next = cur->next->next;
                while(check != NULL){
                    if(check == head && check->val>temp->val){
                        temp->next = check;
                        head = temp;
                        break;
                    }
                    else if(check->val <= temp->val && check->next->val >= temp->val){
                        temp->next = check->next;
                        check->next = temp;
                        break;
                    }
                    check = check->next;
                }
                continue;
            }
            cur = cur->next;
        } 
        return head;
        // ListNode* cur = head;            //跑太慢
        // int total = 0;
        // while(cur != NULL){
        //     total++;
        //     cur = cur->next;
        // }        

        // ListNode* temp;
        // cur = head->next;
        // int count = 0;
        // int record = 0;
        // head->next = NULL;
        // while(count != total-1){
        //     count++;
        //     temp = cur;
        //     cur = cur->next;
        //     temp->next = NULL;
        //     ListNode* check = head;
        //     while(check != NULL){
        //         if(check == head && check->val>temp->val){
        //             temp->next = check;
        //             head = temp;
        //             break;
        //         }
        //         else if(check->next == NULL && check->val<temp->val){
        //             check->next = temp;
        //             temp->next = NULL;
        //             break;
        //         }
        //         else if(check->val <= temp->val && check->next->val >= temp->val){
        //             temp->next = check->next;
        //             check->next = temp;
        //             break;
        //         }
        //         check = check->next;
        //     }
        // }
        // return head;

    }
};
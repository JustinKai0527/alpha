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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)    return head;
        else if(head->next == NULL)    return head;
        else if(left == right)    return head;
        ListNode* mark = NULL;
        ListNode* cur = head;
        int total=0;
        ListNode* reverse = NULL;
        while(cur->next != NULL){
            total++;
            cur = cur->next;
        }
        total++;
        cur = head;
        if(left == 1 && right == total){
            total = 0;
            ListNode* rev_cur = head;
            ListNode* prev = rev_cur;
            ListNode* Next = rev_cur->next;
            while(rev_cur->next != NULL){
                if(total == 0){
                    rev_cur = rev_cur->next;
                    prev->next = NULL;
                    Next = Next->next;
                }
                else{
                    rev_cur->next = prev;
                    prev = rev_cur;
                    rev_cur = Next;
                    Next = Next->next;
                }
                total++;
            }
            rev_cur->next = prev;
            prev = rev_cur;
            head = rev_cur;
        }
        else if(left == 1){
            total = 0;
            reverse = cur;
            while(cur->next != NULL){
                total++;
                if(total == right){                                 //要最後一項所以不用改
                    mark = cur->next;
                    cur->next = NULL;
                    break;
                }
                cur = cur->next;
            }
            ListNode* rev_cur = reverse;
            ListNode* prev = rev_cur;
            ListNode* Next = rev_cur->next;
            while(rev_cur->next != NULL){
                if(total == 0){
                    rev_cur = rev_cur->next;
                    prev->next = NULL;
                    Next = Next->next;
                }
                else{
                    rev_cur->next = prev;
                    prev = rev_cur;
                    rev_cur = Next;
                    Next = Next->next;
                }
                total++;
            }
            rev_cur->next = prev;
            prev = rev_cur;

            head = rev_cur;
            reverse->next = mark;
            
        }
        else if(right == total){
            total = 0;
            while(cur->next != NULL){
                total++;
                if(total == left-1){                                //要前一項
                    reverse = cur->next;
                    mark = cur;
                    break;
                }
                cur = cur->next;
            }
            total = 0;
            ListNode* rev_cur = reverse;
            ListNode* prev = rev_cur;
            ListNode* Next = rev_cur->next;
            while(rev_cur->next != NULL){
                if(total == 0){
                    rev_cur = rev_cur->next;
                    prev->next = NULL;
                    Next = Next->next;
                }
                else{
                    rev_cur->next = prev;
                    prev = rev_cur;
                    rev_cur = Next;
                    Next = Next->next;
                }
                total++;
            }
            rev_cur->next = prev;
            prev = rev_cur;
            mark->next = rev_cur;
        }
        else{
            total = 0;
            while(cur->next != NULL){
                total++;
                if(total == left-1){                                //要前一項
                    reverse = cur->next;
                    mark = cur;
                }
                if(total == right){                                 //要最後一項所以不用改
                    mark->next = cur->next;
                    cur->next = NULL;
                    break;
                }
                cur = cur->next;
            }
            total = 0;

            ListNode* rev_cur = reverse;
            ListNode* prev = rev_cur;
            ListNode* Next = rev_cur->next;
            while(rev_cur->next != NULL){
                if(total == 0){
                    rev_cur = rev_cur->next;
                    prev->next = NULL;
                    Next = Next->next;
                }
                else{
                    rev_cur->next = prev;
                    prev = rev_cur;
                    rev_cur = Next;
                    Next = Next->next;
                }
                total++;
            }
            rev_cur->next = prev;
            prev = rev_cur;

            total = 0;
            cur = head;
            while(cur->next != NULL){
                if(total == left-2){
                    reverse->next = cur->next;
                    cur->next = rev_cur;
                    break;
                }
                total++;
                cur = cur->next;
            }
        }
        return head;
    }
};
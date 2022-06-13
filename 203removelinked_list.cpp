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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* ans = NULL;
        if(head == NULL)    return head;
        while(cur->next != NULL){
            if(cur->val != val){
                ListNode* temp = new ListNode;
                if(ans == NULL){
                    ans = temp;
                    ans->val = cur->val;
                    ans->next = NULL;
                }
                else{
                    ListNode* cur_ans = ans;
                    while(cur_ans->next != NULL){
                        cur_ans = cur_ans->next;
                    }
                    temp->val = cur->val;
                    temp->next = NULL;
                    cur_ans->next = temp;
                }
            }
            cur = cur->next;
        }
        if(cur->val != val){
            ListNode* temp = new ListNode;
            if(ans == NULL){
                ans = temp;
                ans->val = cur->val;
                ans->next = NULL;
            }
            else{
                ListNode* cur_ans = ans;
                while(cur_ans->next != NULL){
                    cur_ans = cur_ans->next;
                }
                temp->val = cur->val;
                temp->next = NULL;
                cur_ans->next = temp;
            }
        }
        return ans;
    }
    void print(ListNode* ans){
        while(ans->next != NULL){
            cout <<ans->val;
            ans = ans->next;
        }
        cout <<ans->val;
    }
};
int main(){
    ListNode a(4);
    ListNode a1(2,&a);
    ListNode list1(1,&a1);
    ListNode b(4);
    ListNode b1(3,&b);
    ListNode list2(1,&b1);
    // ListNode a(1);
    // ListNode a1(2);
    // ListNode list1(1,&a1);
    // // ListNode b(1);
    // ListNode b1(3);
    // ListNode list2(1,&b1);
    Solution c;
    c.print(c.removeElements(&list1,2));
    return 0;
}
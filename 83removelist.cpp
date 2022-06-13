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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        if(head == NULL)    return head;
        while(cur->next != NULL){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
                continue;
            }
            cur = cur->next;
            // cout <<")(*"<<endl;
        }
        return head;
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
    ListNode aa(1);
    ListNode a(1,&aa);
    ListNode a1(1,&a);
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
    // 
    c.print(&list1);
    c.deleteDuplicates(&list1);
    c.print(&list1);
    return 0;
}
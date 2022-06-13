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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = list1;
        if(list1 == NULL && list2 == NULL)    return NULL;
        else if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        while(list2->next != NULL){
            ListNode* cur = ans;
            ListNode* temp = new ListNode;
            temp->val = list2->val;
            temp->next = NULL;
            while(true){
                if(cur->val > list2->val){
                    temp->next = ans;
                    ans = temp;
                    break;
                }
                else if(cur->val <= list2->val && cur->next == NULL){
                    cur->next = temp;
                    break;
                }
                else if(cur->val <= list2->val && cur->next->val > list2->val){
                    temp->next = cur->next;
                    cur->next = temp;
                    break;
                }
                cur = cur->next;
            }
            list2 = list2->next;
        }
        ListNode* cur = ans;
        ListNode* temp = new ListNode;
        temp->val = list2->val;
        temp->next = NULL;
        while(true){
            if(cur->val > list2->val){
                temp->next = ans;
                ans = temp;
                break;
            }
            else if(cur->val <= list2->val && cur->next == NULL){
                cur->next = temp;
                break;
            }
            else if(cur->val <= list2->val && cur->next->val > list2->val){
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
            cur = cur->next;
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
    c.print(c.mergeTwoLists(&list1,&list2));
    return 0;
}
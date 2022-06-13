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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)    return NULL;
        else if(lists.size() == 1)    return lists[0];
    
        for(int i=1; i<lists.size(); i++){
            ListNode* head = lists[0];
            ListNode* cur = head;
            ListNode* link_head = lists[i];
            if(link_head == NULL)    continue;
            if(head == NULL){
                lists[0] = lists[i];
                continue;
            }
            while(link_head != NULL){
                if(cur->val > link_head->val && cur == head){
                    ListNode* temp = link_head;
                    link_head = link_head->next;
                    temp->next = cur;
                    lists[0] = temp;
                    cur = lists[0];
                    continue;
                }
                else if(cur->val < link_head->val && cur->next == NULL){
                    cur->next = link_head;
                    link_head = link_head->next;
                    cur->next->next = NULL;
                    continue;
                }
                else if(cur->val <= link_head->val && cur->next->val >= link_head->val){
                    ListNode* temp = link_head;
                    link_head = link_head->next;
                    temp->next = cur->next;
                    cur->next = temp;
                    continue;
                }
                cur = cur->next;
            }
        }
        return lists[0];
    }
};
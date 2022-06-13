#include <iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)    return NULL;
        else if(head->next == NULL){
            TreeNode* tree_head = new TreeNode(head->val);
            return tree_head;
        }
        else if(head->next->next == NULL){
            TreeNode* tree_head = new TreeNode(head->next->val);
            TreeNode* temp = new TreeNode(head->val);
            tree_head->left = temp;
            return tree_head;
        }
        int total = 0;
        ListNode* cur = head;
        ListNode* prev = head;
        ListNode* Next = head->next;
        while(Next != NULL){
            cur = Next;
            Next = Next->next;
            cur->next = prev;
            prev = cur;
            total++;
        }
        total++;
        head->next = NULL;
        head = cur;
        int count = 0;
        if(total%2 == 0)    count = 1;
        while(count != total/2-1){
            cur = cur->next;
            count++;
        }
        ListNode* right_head = head;
        ListNode* left_head = cur->next;
        cur->next = NULL;

        TreeNode* tree_head = new TreeNode(left_head->val);         //左邊樹
        left_head = left_head->next;
        TreeNode* cur_tree = tree_head;
        while(left_head != NULL){
            TreeNode* temp = new TreeNode(left_head->val);
            cur_tree->left = temp;
            cur_tree = temp;
            left_head = left_head->next;
        }
        
        cur_tree = new TreeNode(right_head->val);                   //右邊樹
        tree_head->right = cur_tree;
        right_head = right_head->next;
        while(right_head != NULL){
            TreeNode* temp = new TreeNode(right_head->val);
            cur_tree->left = temp;
            cur_tree = temp;
            right_head = right_head->next;
        }
        return tree_head;
    }
};
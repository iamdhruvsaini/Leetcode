/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * curr=node;
        ListNode * curr2=node->next;
         ListNode * prev=NULL;

        while(curr2!=NULL){
            swap(curr->val,curr2->val);
            prev=curr;
            curr=curr->next;
            curr2=curr2->next;
        }
        prev->next=NULL;

    }
};
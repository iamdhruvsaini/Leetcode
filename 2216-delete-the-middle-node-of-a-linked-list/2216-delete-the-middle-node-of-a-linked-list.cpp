/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL)return head;
        if(head->next==NULL)return NULL;
        ListNode* prev=head;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* nodeToDelete=prev->next;
        prev->next=prev->next->next;
        delete nodeToDelete;
        return head;
        
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL & n==1))return NULL;
        ListNode * fast=head;
        ListNode * slow=head;

        while(n){
            fast=fast->next;
            n--;
        }

        if(fast==NULL){
            //means its a headnode to delete
            head=head->next;
            return head;
        }
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode * nodeToDelete= slow->next;
        slow->next=slow->next->next;
        delete nodeToDelete;
        return head;
    }
};
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
    ListNode* findMiddle(ListNode* head){
        
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* leftHead, ListNode* rightHead){
        ListNode* merged=new ListNode(-1);
        ListNode * temp=merged;

        while(leftHead!=NULL && rightHead!=NULL){
            if(leftHead->val < rightHead->val){
                temp->next=leftHead;
                leftHead=leftHead->next;
            }
            else{
                temp->next=rightHead;
                rightHead=rightHead->next;
            }

            temp=temp->next;
        }

        while(leftHead!=NULL){
            temp->next=leftHead;
            leftHead=leftHead->next;
            temp=temp->next;
        }
        while(rightHead!=NULL){
            temp->next=rightHead;
            rightHead=rightHead->next;
            temp=temp->next;
        }

        return merged->next;
    }

   


    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *middle=findMiddle(head);
        ListNode * leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=NULL;

        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);

        return merge(leftHead,rightHead);

    }
};
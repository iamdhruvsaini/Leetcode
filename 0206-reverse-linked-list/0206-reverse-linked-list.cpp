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
    void findReverse(ListNode * prev, ListNode* curr,ListNode* &ans){

        if(curr->next==NULL){
            ans=curr;
            curr->next=prev;

            prev->next=NULL;
            return;
        }



        findReverse(curr,curr->next,ans);
        curr->next=prev;
        if(prev!=NULL)prev->next=NULL;

    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* ans=NULL;
        findReverse(NULL,head,ans);
        return ans;
    }
};
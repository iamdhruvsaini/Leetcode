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
    ListNode* reverseList(ListNode* head){

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next_node=NULL;

        while(curr!=NULL){
            next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
        }

        return prev;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* tail=head;


        // Now add the 2 nos
        int carry=0;
        while(l1!=NULL && l2!=NULL){

            ListNode* temp=new ListNode(-1);
            int sum=l1->val+l2->val+carry;
            int rem=sum%10;
            carry=sum/10;
            temp->val=rem;
            tail->next=temp;
            tail=tail->next;

            l1=l1->next;
            l2=l2->next;
        }


        while(l1!=NULL){
            ListNode* temp=new ListNode(-1);
            int sum=l1->val+carry;
            int rem=sum%10;
            carry=sum/10;
            temp->val=rem;
            tail->next=temp;
            tail=tail->next;

            l1=l1->next;
        }
        while(l2!=NULL){
            ListNode* temp=new ListNode(-1);
            int sum=l2->val+carry;
            int rem=sum%10;
            carry=sum/10;
            temp->val=rem;
            tail->next=temp;
            tail=tail->next;


            l2=l2->next;
        }


        while(carry){
            int rem=carry%10;
            ListNode* temp=new ListNode(-1);
            temp->val=rem;
            tail->next=temp;
            tail=tail->next;
            carry/=10;
        }
        return (head->next);



    }
};
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
    ListNode * findMiddle(ListNode* head){
        ListNode * slow=head;
        ListNode * fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

    }

    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next_node = NULL;

        while (current != NULL) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        return prev;
    }


    bool isPalindrome(ListNode* head) {

        ListNode * mid=findMiddle(head);
        ListNode * head2=reverseList(mid);

        ListNode * top1=head;
        ListNode * top2=head2;

        while(top1!=NULL && top2!=NULL){
            if(top1->val!=top2->val)return false;
            else{
                top1=top1->next;
                top2=top2->next;
            }
        }

        return true;




    }
};
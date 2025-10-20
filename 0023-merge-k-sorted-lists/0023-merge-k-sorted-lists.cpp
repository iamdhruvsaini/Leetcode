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

//  #include<queue>
class Solution {
public:
     class Compare{

        public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
     };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // declaring the min Heap
        priority_queue<ListNode*, vector<ListNode *>, Compare>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        
        ListNode * head=new ListNode(-1);
        ListNode * tail=head;

        while(!pq.empty()){
            ListNode * mini=pq.top();
            pq.pop();

            tail->next=mini;
            tail=tail->next;
            
            if(mini->next!=NULL){
                pq.push(mini->next);
            }
        }

        return head->next;
    }
};
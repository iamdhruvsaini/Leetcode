class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();
        // if(k>n){
        //     return -1;
        // }

        // int i=0;
        // while(i<k){
        //     pq.push(nums[i]);
        //     i++;
        // }
        // for(;i<n;i++){
        //     if(nums[i]>pq.top()){
        //         pq.pop();
        //         pq.push(nums[i]);
        //     }
        // }

        // return pq.top();

    }
};
class Solution {
public:

    bool possible(vector<int>& nums,int target,int s){
        // This function checks whether it is possible to have          subarray of size 's' whose sum is >= target.

        int totalsum=0;
        //sum of first possible s size subarray
        for(int i=0;i<s;i++){
            totalsum+=nums[i];
        }
        if(totalsum >= target){
            return true; //possible size 
        }

        //now check other subarray of same size

        for(int i=s;i<nums.size();i++){
            totalsum-=nums[i-s];//this is maitain the size of array
            totalsum+=nums[i];
            if(totalsum>=target)return true;//possible size
        }

        return false; //not possible 

    }
    int minSubArrayLen(int target, vector<int>& nums) {
        //Binary Search
        int s=0;
        int e=nums.size();//maximum size of subarray
        int ans=0; //possible answer
        //Now we will try to minimize the size of possible subarray
        while(s<=e){
            int mid=s+(e-s)/2;

            if(possible(nums,target,mid)){
                ans=mid;//its a possibe answer now we want to minimize size
                e=mid-1;
            }
            else{//not possible to generate target sum with given size so increase the size
                s=mid+1;
            }
        }

        return ans;

        
        
    }
};
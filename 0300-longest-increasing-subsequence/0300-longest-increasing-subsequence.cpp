class Solution {
public:
    int f(vector<int>& nums,int index,int prev,vector<vector<int>>&dp){
        if(index==nums.size())return 0;
        if(dp[index][prev+1]!=-1)return dp[index][prev+1];

        int notTake=f(nums,index+1,prev,dp);
        int take=0;
        if(prev==-1 || nums[index]>nums[prev]){
            take=1+f(nums,index+1,index,dp);
        }

        return dp[index][prev+1]=max(notTake,take);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
        
    }
};
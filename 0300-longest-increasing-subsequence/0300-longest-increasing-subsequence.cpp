class Solution {
public:
    int f(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int skip=f(nums,i+1,prev,dp);
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+f(nums,i+1,i,dp);
        }
        return dp[i][prev+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // we have to shift the coordinates
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
        
    }
};
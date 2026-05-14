class Solution {
public:
    int f(vector<int>&nums,int i, vector<int>&dp){
        if(i==0)return nums[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int notTake=f(nums,i-1,dp);   
        int take=nums[i]+f(nums,i-2,dp);
     
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(nums,n-1,dp);
    }
};
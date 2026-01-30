class Solution {
public:
    bool solve(vector<int>& nums,int sum,int index, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(index==0){
            return sum==nums[index];
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notTake=solve(nums,sum,index-1,dp);
        int take=0;
        if(nums[index]<=sum){
            take=solve(nums,sum-nums[index],index-1,dp);
        }
        return dp[index][sum]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum & 1)return false;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(total_sum/2 + 1,-1));
        return solve(nums,total_sum/2,n-1,dp);
    
    }
};
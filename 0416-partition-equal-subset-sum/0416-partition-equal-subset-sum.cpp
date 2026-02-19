class Solution {
public:
    bool solve(vector<int>& nums,int index,int sum, vector<vector<int>>&dp){
        if(sum == 0)return true;
        if(index==0)return sum==nums[index];
        if(dp[index][sum]!=-1)return dp[index][sum];

        // nottake
        int notTake=solve(nums,index-1,sum,dp);
        int take=false;
        if(sum - nums[index]>=0){
            take=solve(nums,index-1,sum-nums[index],dp);
        }
        return dp[index][sum]= take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        if(total & 1)return false;
        return solve(nums,n-1,total/2,dp);

    }
};
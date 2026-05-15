class Solution {
public:
    int f(vector<int>& nums,int i,int t,vector<vector<int>>&dp){
        if(t==0)return 1;
        if(i==0)return nums[i]==t;
        if(dp[i][t]!=-1)return dp[i][t];

        int case1=f(nums,i-1,t,dp);
        int case2=0;
        if(t-nums[i]>=0){
            case2=f(nums,i-1,t-nums[i],dp);
        }
        return dp[i][t]=case1||case2;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return 0;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));

        return f(nums,n-1,sum/2,dp);
    }
};
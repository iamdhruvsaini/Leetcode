class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];

        int case1=solve(n-1,dp);
        int case2=solve(n-2,dp);

        return dp[n]=case1+case2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);

    }
};
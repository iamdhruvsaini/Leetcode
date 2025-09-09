class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int>& dp){
        if(n==0)return cost[0];
        if(n==1)return cost[1];

        if(dp[n]!=-1)return dp[n];

        if(n==cost.size()){
            dp[n] = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
            return dp[n];
        }
        else{
            dp[n] = min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
            return dp[n];

        }

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(cost,n,dp);
    }
};
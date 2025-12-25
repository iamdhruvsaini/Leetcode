class Solution {
public:
    int solve(vector<int>& coins,int amount,vector<int>&dp){
        if(amount==0)return 0;
        if(amount<0)return -1;
        if(dp[amount]!=-2)return dp[amount];

        int count=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int check=solve(coins,amount-coins[i],dp);
            if(check!=-1){
                count=min(count,check+1);
            }
        }
        return dp[amount]=count==INT_MAX?-1:count;

    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,-2);
        return solve(coins,amount,dp);

        
    }
};
class Solution {
public:
    int f( vector<int>& coins,int index,int amount,vector<vector<int>>&dp){
        
        if(index==0){
            return amount % coins[index]==0;
        }
        if(amount==0)return 1;

        if(dp[index][amount]!=-1)return dp[index][amount];

        int notTake=f(coins,index-1,amount,dp);
        int take=0;
        if(coins[index]<=amount){
            take=f(coins,index,amount-coins[index],dp);
        }
        return dp[index][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins,coins.size()-1,amount,dp);
    }
};
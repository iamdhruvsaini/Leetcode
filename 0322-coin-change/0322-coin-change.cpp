class Solution {
public:
    int f(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){

        if(i==0){
            if(amount%coins[i]==0)return amount/coins[i];
            else return 1e9;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        // not take current coin
        int notTake=f(coins,amount,i-1,dp);

        // take the current coin
        int take=1e9;
        if(amount-coins[i]>=0){
            // add 1 for considering th coin
            take=1+f(coins,amount-coins[i],i,dp);
        }

        return dp[i][amount] = min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(coins,amount,n-1,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};
class Solution {
public:
    int f(vector<int>&coins,int i,int amt, vector<vector<int>>&dp){
        if(amt==0)return 0;
        // coins made by 0th coins
        if(i==0){
            if(amt%coins[i]==0)return amt/coins[i];
            else return 1e9;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];

        int notTake=0+f(coins,i-1,amt,dp);
        // take
        int take=1e9;

        if(amt-coins[i]>=0){
            // as we can repeat the coins na
            take=1+f(coins,i,amt-coins[i],dp);
        }

        return dp[i][amt]=min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans=f(coins,n-1,amount,dp);
        return ans==1e9?-1:ans;
    }
};
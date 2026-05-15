class Solution {
public:
    int f(vector<int>& coins, int i, int amt,vector<vector<int>>&dp) {
        if (amt == 0) return 1;

        if (i == 0) {
            return (amt % coins[0] == 0);
        }
        if(dp[i][amt]!=-1)return dp[i][amt];

        int notTake = f(coins, i - 1, amt,dp);

        int take = 0;
        if (coins[i] <= amt) {
            take = f(coins, i, amt - coins[i],dp);
        }

        return dp[i][amt]=take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins, n - 1, amount,dp);
    }
};
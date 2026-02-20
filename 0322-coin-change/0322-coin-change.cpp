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
        vector<int>dp1(amount+1,-1),dp2(amount+1,-1);
        // int ans=f(coins,amount,n-1,dp);

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp1[i]=i/coins[0];
            else dp1[i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notTake=dp1[amt];
                 // take the current coin
                 int take=1e9;
                 if(amt-coins[i]>=0){
                     // add 1 for considering th coin
                     take=1+dp2[amt-coins[i]];
                 }
                 dp2[amt] = min(take,notTake);

            }
            dp1=dp2;
        }
        if(dp1[amount]!=1e9)return dp1[amount];
        return -1;
    }
};
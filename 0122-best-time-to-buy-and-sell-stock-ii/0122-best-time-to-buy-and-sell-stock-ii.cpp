class Solution {
public:
    int f(vector<int>& prices,int index,int buy,vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1)return dp[index][buy];

        int profit=0;

        if(buy){
            profit=max(-1*prices[index]+f(prices,index+1,0,dp), f(prices,index+1,1,dp));
        }
        else{
            profit=max(prices[index]+f(prices,index+1,1,dp), f(prices,index+1,0,dp));
        }
        return dp[index][buy]=profit;

    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1)); 
        return f(prices,0,1,dp);
    }
};
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
        vector<vector<int>>dp(n+1,vector<int>(2,-1)); 
        // return f(prices,0,1,dp);
        function<int()>fnc=[&](){
            // intialize the base case
            dp[n][0]=0;
            dp[n][1]=0;

            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;

                    if(buy){
                        profit=max(-1*prices[i]+dp[i+1][0], dp[i+1][1]);
                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1], dp[i+1][0]);
                    }
                    dp[i][buy]=profit;
                }
            }

            return dp[0][1];
        };

        return fnc();

    }
};
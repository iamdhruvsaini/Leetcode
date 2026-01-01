class Solution {
public:
    int f(vector<int>& prices,int index,int buy,int cap, vector<vector<vector<int>>>&dp){
        if(cap==0)return 0;
        if(index==prices.size())return 0;
        if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];

        if(buy){
            // you can invest or can skip
            return dp[index][buy][cap] = max(-prices[index]+f(prices,index+1,0,cap,dp) , f(prices,index+1,1,cap,dp));
        }
        else{
            // you can sell or sell later
            return dp[index][buy][cap] = max(prices[index]+f(prices,index+1,1,cap-1,dp), f(prices,index+1,0,cap,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        // 3d dp
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        auto fnc=[&](){
            for(int index=n-1;index>=0;index--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
                        if(buy){
                            // you can invest or can skip
                            dp[index][buy][cap] = max(-prices[index]+dp[index+1][0][cap] , dp[index+1][1][cap]);
                        }
                        else{
                            // you can sell or sell later
                            dp[index][buy][cap] = max(prices[index]+dp[index+1][1][cap-1], dp[index+1][0][cap]);
                        }

                    }
                }
            }

            return dp[0][1][2];

        };

        return fnc();
        // return f(prices,0,1,2,dp);

    }
};
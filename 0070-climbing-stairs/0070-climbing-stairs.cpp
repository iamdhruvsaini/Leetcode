class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];

        int case1=solve(n-1,dp);
        int case2=solve(n-2,dp);

        return dp[n]=case1+case2;
    }

    int tabulation(int n){
        vector<int>dp(n+1,-1);
        dp[0]=1;

        for(int i=1;i<=n;i++){
            int case1=0;
            if(i-1 >=0){
                case1=dp[i-1];
            }
            int case2=0;
            if(i-2>=0){
                case2=dp[i-2];
            }

            dp[i]=case1+case2;

        }


        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return tabulation(n);

    }
};
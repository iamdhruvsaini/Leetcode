class Solution {

public:
    int solve(vector<vector<int>>& triangle, int index,int prev,vector<vector<int>>&dp){
        int n=triangle.size();
        if(index==n-1){
            // return min(triangle[index][prev],triangle[index][prev+1]);
            return triangle[index][prev];
        }
        if(dp[index][prev]!=-1)return dp[index][prev];
        int case1=triangle[index][prev]+solve(triangle,index+1,prev,dp);
        int case2=triangle[index][prev]+solve(triangle,index+1,prev+1,dp);

        return dp[index][prev]=min(case1,case2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n);
        for(int i = 0; i < n; i++)
            dp[i] = vector<int>(n, -1);

        // initialize the base case
        for(int i=0;i<n;i++)dp[n-1][i]=triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int case1=triangle[i][j]+dp[i+1][j];
                int case2=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(case1,case2);

            }
        }
        return dp[0][0];
    }

};
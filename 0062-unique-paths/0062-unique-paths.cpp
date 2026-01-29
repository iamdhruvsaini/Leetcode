class Solution {
public: 
    int solve(int n,int m ,int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        // move top
        int case1=solve(n,m,row-1,col,dp);
        int case2=solve(n,m,row,col-1,dp);

        return dp[row][col]=case1+case2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(n,m,m-1,n-1,dp);
    }
};
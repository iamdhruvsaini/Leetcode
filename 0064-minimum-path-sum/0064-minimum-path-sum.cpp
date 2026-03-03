class Solution {
public:
    int f(vector<vector<int>>& mat,int r,int c,vector<vector<int>>&dp){
        if(r==0 && c==0)return mat[0][0];
        if(r<0 || c<0)return 1e9;
        if(dp[r][c]!=-1)return dp[r][c];

        // move up
        int case1=mat[r][c]+f(mat,r-1,c,dp);
        // move left
        int case2=mat[r][c]+f(mat,r,c-1,dp);

        return dp[r][c] = min(case1,case2);
    }
    int minPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(mat,n-1,m-1,dp);
        
        
    }
};
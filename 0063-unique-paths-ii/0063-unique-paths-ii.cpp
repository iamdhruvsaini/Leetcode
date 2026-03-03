class Solution {
public:
    int f(vector<vector<int>>& mat,int r,int c,  vector<vector<int>>&dp){
        int n=mat.size(),m=mat[0].size();
        if(r<0 || c<0 || r>=n || c>=m)return 0;
        // if there is a stone in path
        if(mat[r][c]==1)return 0;

        if(r==0 && c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];

        // upward move
        int case1=f(mat,r-1,c,dp);
        // left move
        int case2=f(mat,r,c-1,dp);

        return dp[r][c]=case1+case2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(mat,n-1,m-1,dp);
    }
};
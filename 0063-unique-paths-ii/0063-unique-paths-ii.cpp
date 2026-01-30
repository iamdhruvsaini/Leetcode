class Solution {
public:
    int solve(vector<vector<int>>& grid,int r,int c,vector<vector<int>>&dp){
        if(r<0 || c<0)return 0;
        if(grid[r][c]==1)return 0;
        if(r==0 && c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int case1=solve(grid,r,c-1,dp);
        int case2=solve(grid,r-1,c,dp);
        return dp[r][c]=case1+case2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(grid[0][0] == 1) return 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(grid[r][c] == 1) {
                dp[r][c] = 0;
                continue;
            }
            if(r == 0 && c == 0) continue;

            int case1 = (c >= 1) ? dp[r][c-1] : 0;
            int case2 = (r >= 1) ? dp[r-1][c] : 0;

            dp[r][c] = case1 + case2;
        }
    }
    return dp[n-1][m-1];
}

};
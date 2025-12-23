class Solution {
public:
    int f(vector<vector<int>>& grid,int i,int j, vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left=f(grid,i,j-1,dp);
        int right=f(grid,i-1,j,dp);

        return dp[i][j]=left+right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return f(obstacleGrid,m-1,n-1,dp);
        
    }
};
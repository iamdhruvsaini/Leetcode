class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        int n = matrix.size();

        // Boundary check
        if (col < 0 || col >= n) {
            return 1e9; // Use a larger value to avoid collisions with real sums
        }
        
        // Base case: Reached the last row
        if (row == n - 1) {
            return matrix[row][col];
        }

        // Memoization check
        if (dp[row][col] != -1) return dp[row][col];

        // Explore 3 paths
        int straight = matrix[row][col] + solve(matrix, row + 1, col, dp);
        int leftDiag = matrix[row][col] + solve(matrix, row + 1, col - 1, dp);
        int rightDiag = matrix[row][col] + solve(matrix, row + 1, col + 1, dp);
    
        return dp[row][col] = min({straight, leftDiag, rightDiag});
    }
    int tabulation(vector<vector<int>>& matrix){
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }

        for(int row=n-2;row>=0;row--){
           for(int col=0;col<n;col++){
                int straight = matrix[row][col] + dp[row + 1][col];

                int leftDiag = 1e9;
                int rightDiag = 1e9;
                if(col>0){
                    leftDiag=matrix[row][col] + dp[row + 1][col-1];
                }
                if(col+1 < n){
                    rightDiag = matrix[row][col] + dp[row + 1][col+1];
                }
                dp[row][col]=min({straight, leftDiag, rightDiag});
           }
        }

        int ans = 1e9;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[0][i]);
    }
    return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
    
        return tabulation(matrix);
        // vector<vector<int>> dp(n, vector<int>(n, -1)); 
        
        // for (int i = 0; i < n; i++) {
        //     ans = min(ans, solve(matrix, 0, i, dp));
        // }

        // return ans;
    }
};
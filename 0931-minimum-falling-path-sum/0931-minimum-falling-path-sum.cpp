class Solution {
public:
    int solve(vector<vector<int>>& matrix,int index,int c,vector<vector<int>>&dp){
        int n=matrix.size();
        if(c < 0 || c>=n)return 1e6;
        if(index==n-1){
            return matrix[index][c];
        }
        if(dp[index][c]!=-1)return dp[index][c];
        int case1=matrix[index][c]+solve(matrix,index+1,c,dp);
        int case2=matrix[index][c]+solve(matrix,index+1,c+1,dp);
        int case3=matrix[index][c]+solve(matrix,index+1,c-1,dp);

        return dp[index][c]=min({case1,case2,case3});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        // int mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     mini=min(mini,solve(matrix,0,i,dp));
        // }
        // return mini;
        for(int i=0;i<n;i++){
           dp[n-1][i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int c=n-1;c>=0;c--){
                int case1=matrix[i][c]+dp[i+1][c];
                int case2=INT_MAX,case3=INT_MAX;
                if(c+1 < n){
                    case2=matrix[i][c]+dp[i+1][c+1];
                }
                if(c-1 >= 0){
                    case3=matrix[i][c]+dp[i+1][c-1];
                }
                dp[i][c]=min({case1,case2,case3});
            }
        }

        return *min_element(dp[0].begin(),dp[0].end());
        
    }
};
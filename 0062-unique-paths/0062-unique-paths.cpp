class Solution {
public:
    int f(int i,int j, vector<vector<int>>&dp){

        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int case1=f(i,j-1,dp);
        int case2=f(i-1,j,dp);
        return dp[i][j]=case1+case2;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,dp);
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;

                int case1=0;
                if(j>=1){
                   case1=dp[i][j-1];
                }
                
                int case2=0;
                if(i>=1){
                    case2=dp[i-1][j];
                }
                
                dp[i][j]=case1+case2;

            }
        }

        return dp[m-1][n-1];
        
    }
};
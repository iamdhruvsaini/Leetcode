class Solution {
public:
    int f(int n,int m,int r,int c, vector<vector<int>>&dp){
        if(r==0 && c==0)return 1;

        if(r<0 || c<0 || r>=n || c>=m)return 0;
        if(dp[r][c]!=-1)return dp[r][c];


        // robot can move up or left only
        // up case
        int case1=f(n,m,r-1,c,dp);
        // down case
        int case2=f(n,m,r,c-1,dp);

        return dp[r][c]=case1+case2;


    }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        // tabulation
        dp[0][0]=1;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                // up case
                if(r==0 && c==0)continue;
                int case1=0;
                if(r-1 >= 0){
                    case1=dp[r-1][c];
                }
                // down case
                int case2=0;
                if(c-1 >=0){
                    case2=dp[r][c-1];
                }

                dp[r][c]=case1+case2;

            }
        } 
        return dp[m-1][n-1];       
    }
};
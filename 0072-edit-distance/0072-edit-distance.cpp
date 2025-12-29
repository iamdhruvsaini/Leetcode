class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)return 0;
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];

        if(word1[i-1]==word2[j-1]){
            return solve(word1,word2,i-1,j-1,dp);
        }
        return 1+min(solve(word1,word2,i,j-1,dp),
        min(solve(word1,word2,i-1,j,dp),solve(word1,word2,i-1,j-1,dp))
        );
    }

    int tabulation(string word1, string word2){
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        // Base Case initialized
        for(int i=0;i<=m;i++)dp[0][i]=i;
        for(int i=0;i<=n;i++)dp[i][0]=i;
        dp[0][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i][j-1],
                    min(dp[i-1][j],dp[i-1][j-1]));
                }

            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {

        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(word1,word2,n,m,dp);
        return tabulation(word1,word2);
    }
};
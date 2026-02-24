class Solution {
public:
    int f( string s1, string s2, vector<vector<int>>&dp){
        int n=s1.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
       string s1=s;
       reverse(s1.begin(),s1.end());
       int n=s.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       int lps=f(s1,s,dp); 
       return n-lps;
    }
};
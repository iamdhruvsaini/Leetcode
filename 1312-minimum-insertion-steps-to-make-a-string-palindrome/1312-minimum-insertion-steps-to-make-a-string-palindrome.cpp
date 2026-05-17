class Solution {
public:

    int minInsertions(string s) {
        /*
            find the Longest common subsequence
            return the s.length()-len(lcs);
        */
        int n=s.size();
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];

        
    }
};
class Solution {
public:
    int minInsertions(string s) {

        string t1=s;
        reverse(s.begin(),s.end());
        string t2=s;
        int n=t1.length();
        int m=t2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        auto fnc=[&](){
            for(int i=0;i<=n;i++)dp[i][0]=0;
            for(int j=0;j<=m;j++)dp[0][j]=0;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(t1[i-1]==t2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }

                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
            return dp[n][m];
        };

        return n-fnc();
        
    }
};
class Solution {
public:
    int f(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1;

        // pattern exhausted
        if(j == 0) return 0;

        // string exhausted
        if(i == 0) {
            for(int k = 1; k <= j; k++) {
                if(p[k-1] != '*') return 0;
            }
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '?') {
            return dp[i][j] = f(s, p, i-1, j-1, dp);
        }

        else if(p[j-1] == '*') {
            int case1 = f(s, p, i-1, j, dp);   // match one/more chars
            int case2 = f(s, p, i, j-1, dp);   // match empty
            return dp[i][j] = case1 || case2;
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++){
            for(int k = 1; k <= j; k++) {
                if(p[k-1] != '*') dp[0][j] = 0;
            }
            if(dp[0][j]!=0)dp[0][j]=1;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(p[j-1] == '*') {
                    int case1 = dp[i-1][j];   // match one/more chars
                    int case2 = dp[i][j-1];   // match empty
                    dp[i][j] = case1 || case2;
                }

                else dp[i][j] = 0;

            }
        }
        return dp[n][m];

        // return f(s, p, n, m, dp);

    }
};
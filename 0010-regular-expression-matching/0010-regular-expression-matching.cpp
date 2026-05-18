class Solution {
public:
    int f(string s, string p, int i, int j, vector<vector<int>>& dp) {

        if(i == 0 && j == 0) return 1;

        if(j == 0) return 0;

        if(i == 0) {
            for(int k = 1; k <= j; k += 2) {
                if(k == j || p[k] != '*')
                    return 0;
            }
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '.') {
            return dp[i][j] = f(s, p, i-1, j-1, dp);
        }

        else if(p[j-1] == '*') {

            // zero occurrence
            int case1 = f(s, p, i, j-2, dp);

            // one or more occurrence
            int case2 = 0;

            if(p[j-2] == s[i-1] || p[j-2] == '.') {
                case2 = f(s, p, i-1, j, dp);
            }

            return dp[i][j] = (case1 || case2);
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(s, p, n, m, dp);
    }
};
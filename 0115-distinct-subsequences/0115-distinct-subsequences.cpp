class Solution {
public:
    int f(string s,string t,int i,int j, vector<vector<int>>&dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i-1]==t[j-1]){
            return dp[i][j] = f(s,t,i-1,j-1,dp)+f(s,t,i-1,j,dp);
        }
        else{
            return dp[i][j] = f(s,t,i-1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(s,t,n,m,dp);
        
        
    }
};
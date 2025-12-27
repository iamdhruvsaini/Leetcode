class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        function<int(int,int)>fnc=[&](int i,int j){
            if(j==0)return 1;
            if(i==0)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            if(s[i-1]==t[j-1]){
                return dp[i][j]=fnc(i-1,j-1)+fnc(i-1,j);
            }
            return dp[i][j]=fnc(i-1,j);
        };
        return fnc(n,m);
        
    }
};
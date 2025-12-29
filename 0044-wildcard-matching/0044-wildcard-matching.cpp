class Solution {
public:
    bool solve(string s,string p,int i,int j,vector<vector<int>>&dp){
        
        if(i==0 && j==0)return true;
        if(i==0){
            for(;j>=1;j--){
                if(p[j-1]!='*')return false;
            }
            return true;
        }
        if(j==0){
            return false;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j] = solve(s,p,i-1,j-1,dp);
        }
        else if(p[j-1]=='*'){
            // two cases possible
            return dp[i][j] = solve(s,p,i,j-1,dp) || solve(s,p,i-1,j,dp);
        }
        return false;
    } 
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        auto fnc=[&](){
            // base case initialized
            dp[0][0]=true;
            for(int i=1;i<=n;i++)dp[i][0]=0;
            
            for(int j=1;j<=m;j++){
                bool flag=true;
                for(int jj=j;jj>=1;jj--){
                    if(p[jj-1]!='*'){
                        dp[0][j]= false;
                        flag=false;
                        break;
                    };
                }
                if(flag){
                    dp[0][j]=true;
                }
            }


            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==p[j-1] || p[j-1]=='?'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*'){
                        // two cases possible
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    }
                    else{
                        dp[i][j]=false;
                    }                   

                }
            }

            return dp[n][m];

        };

        return fnc();
    }
};
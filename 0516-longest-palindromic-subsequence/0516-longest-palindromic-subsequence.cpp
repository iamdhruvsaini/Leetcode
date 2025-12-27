class Solution {
public:
    int longestPalindromeSubseq(string s) {

        string text1=s;
        reverse(s.begin(),s.end());
        string text2=s;
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        function<int(int,int)>fnc=[&](int index1,int index2){
            if(index1 == 0 || index2 == 0)return 0;
            
            if(dp[index1][index2]!=-1)return dp[index1][index2];

            if(text1[index1-1]==text2[index2-1]){
                return dp[index1][index2]=1+fnc(index1-1,index2-1);
            }


            return dp[index1][index2]=max(fnc(index1-1,index2),fnc(index1,index2-1));
        
        };


        auto tabulation=[&](){
            for(int i=0;i<=n;i++)dp[i][0]=0;
            for(int i=0;i<=m;i++)dp[0][i]=0;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }

            return dp[n][m];
        };

        return tabulation();

        
    }
};
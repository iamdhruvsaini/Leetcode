class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    int solve(string s,int i,vector<int>&dp){
        int n=s.size();
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                int cnt=1+solve(s,j+1,dp);
                mini=min(cnt,mini);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);

        // return solve(s,0,dp)-1;

        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    int cnt=1+dp[j+1];
                    mini=min(cnt,mini);
                }
            }
            dp[i]=mini;

        }
        return dp[0]-1;
        
    }
};
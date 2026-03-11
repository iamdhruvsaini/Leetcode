class Solution {
public:
    class Compare{
        public:
        bool operator()(string a, string b){
            return a.length()<b.length();
        }
    };

    bool check(string &a,string &b){
        // a length is more than b
        if(a.length()!=b.length()+1)return false;
        int i=0,j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else if(a[i]!=b[j]){
                i++;
            }
        }
        return j==b.length();
    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),Compare());
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(check(words[i],words[j]) && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                    maxi=max(maxi,dp[i]);
                }
            }
        }

        return maxi;
        
    }
};
class Solution {
public:
    bool isValid(string &str1,string &str2){
        /*
            abb
            ab
        */
        if(str1.length()!=str2.length()+1)return 0;

        int i=0,j=0;
        while(i<str1.length()){
            if(str1[i]==str2[j]){
                i++;
                j++;
            }
            else{
               i++;
            }
        }
        return j==str2.length();
    }
    class Compare{
        public:
        bool operator()(string str1,string str2){
            return str1.length()<str2.length();
        }
    };
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);

        sort(words.begin(),words.end(),Compare());
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[i],words[j]) && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
        
    }
};
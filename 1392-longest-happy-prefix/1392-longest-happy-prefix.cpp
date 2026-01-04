class Solution {
public:
    string longestPrefix(string s) {
        // we have to find the longest prefix suffix

        int n=s.size();
        vector<int>lps(n,0);

        int pre=0,suff=1;
        while(suff<n){
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lps[suff++]=0;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        string ans="";
        for(int i=0;i<lps[n-1];i++){
            ans+=s[i];
        }
        return ans;
    }
};
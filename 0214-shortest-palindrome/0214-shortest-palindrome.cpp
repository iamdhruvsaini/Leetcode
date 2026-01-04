class Solution {
public:
    string shortestPalindrome(string s) {
        if(s=="")return "";
        string ans="";
        string temp=s;
        string str=s;
        reverse(s.begin(),s.end());
        str+='$';
        str+=s;

        // find lps of it
        int n=str.size();
        vector<int>lps(n,0);

        int pre=0, suff=1;
        while(suff<n){
            if(str[pre]==str[suff]){
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
        int len=lps[n-1];
        for (int i=len;i<s.size();i++){
            ans+=str[i];
        }
        reverse(ans.begin(),ans.end());
        ans+=temp;
        return ans;
        
    }
};
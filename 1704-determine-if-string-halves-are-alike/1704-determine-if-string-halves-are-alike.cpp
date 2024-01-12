class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int n1=n/2;
        string str="aeiouAEIOU";
        int cnt=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<str.length();j++){
                if(s[i]==str[j] && i<n1)cnt++;
                else if(s[i]==str[j] && i>=n1)cnt--;
            }
        }
        return cnt==0;
    }
};
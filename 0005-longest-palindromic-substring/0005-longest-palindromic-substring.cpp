class Solution {
public:
    string longestPalindrome(string s) {
        string str="#";

        for(auto ch:s){
            str+=ch;
            str+='#';
        }

        int n=str.length();
        vector<int>p(n,1);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(i<r){
                p[i]=min(r-i,p[r+l-i]);
            }
            while(i+p[i]<n && i-p[i]>=0 && str[i+p[i]]==str[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<p[i]<<" ";
        // }
        int maxLen = 0, center = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        
        int start = (center - maxLen + 1) / 2;
        return s.substr(start, maxLen - 1);
        
    }
};
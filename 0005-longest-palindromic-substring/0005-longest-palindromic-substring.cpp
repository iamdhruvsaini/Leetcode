class Solution {
public:
    /*
        aba -> 3
        #a#b#a# -> 7

    */
    string longestPalindrome(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
            str+='#';
            str+=s[i];
        }
        str+='#';
        int n=str.size();
        int l=0,r=0;
        vector<int>p(n,0);

        for(int i=0;i<n;i++){
            if(i<r){
                p[i]=min(r-i,p[l+r-i]);
            }
             while(i+p[i]<n && i-p[i]>=0 && str[i+p[i]]==str[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }

        int maxLen = 0, center = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }
        
        int start = (center -(maxLen - 1)) / 2;
        return s.substr(start, maxLen - 1);
        
    }
};
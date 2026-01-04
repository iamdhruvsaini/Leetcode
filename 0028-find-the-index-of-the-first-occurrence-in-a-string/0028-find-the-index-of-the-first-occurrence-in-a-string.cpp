class Solution {
public:
    vector<int>getLps(string needle){
        int n=needle.size();
        vector<int>lps(n,0);
        int pre=0,suff=1;
        while(suff<n){
            if(needle[pre]==needle[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }

        return lps;

    }

    int strStr(string haystack, string needle) {
        // Find the LPS of needle
        int n=needle.size();
        int m=haystack.size();
        vector<int>lps=getLps(needle);
         int  i=0,j=0;

         while(i<n && j<m){
            if(haystack[j]==needle[i]){
                i++;
                j++;
            }
            else{
                if(i==0){
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }
         }

        if(i==n){   
            return j-i;
        }
        return -1;
    }
};
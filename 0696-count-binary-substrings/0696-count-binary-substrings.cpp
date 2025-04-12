class Solution {
public:
    int countBinarySubstrings(string s) {

        int prev=0;
        int curr=1;
        int ans=0;

        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
            else{
                curr++;
            }
        }
         ans += min(prev, curr);
        return ans;
    }
};
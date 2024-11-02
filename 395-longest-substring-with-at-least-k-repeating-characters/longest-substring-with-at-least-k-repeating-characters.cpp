class Solution {
public:

    int solve(string &s,int k){
        unordered_map<char,int>mp;
        if(s.size()<k || s=="")return 0;
        for(auto c: s){
            mp[c]++;
        }
        int ans=0;
        string temp="";
        for(auto c:s){
            if(mp[c]<k){
                ans=max(ans,solve(temp,k));
                temp="";
            }
            else{
                temp+=c;
            }
        }
        if(temp==s)return temp.length();
        ans=max(ans,solve(temp,k));
        return ans;


    }
    int longestSubstring(string s, int k) {
       

        return solve(s,k);
    }
};
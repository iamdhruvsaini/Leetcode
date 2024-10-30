class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mp;

        int left=0;
        int right=0;
        int ans=0;
        while(right<s.size()){
            if(mp.find(s[right])!=mp.end() && mp[s[right]]==true){
                mp[s[right]]=false;
                char temp=s[right];
                while(s[left]!=temp){
                    mp[s[left]]=false;
                    left++;
                }
                left++;
                ans=max(ans,right-left+1);
            }
            else{
                mp[s[right]]=true;
                ans=max(ans,right-left+1);
                right++;
            }
        }
        // ans=max(ans,right-left);
        return ans;
    }
};
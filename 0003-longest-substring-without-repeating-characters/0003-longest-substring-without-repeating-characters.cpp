class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        int low=0;
        int high=0;
        int ans=INT_MIN;
        unordered_map<char,int>mp;
        while(high<s.size() && low<s.size()){
            mp[s[high]]++;
            if(mp[s[high]]<=1){
                ans=max(ans,high-low+1);
                high++;
            }
            else{
                while(mp[s[high]]>1){
                    mp[s[low]] -- ;
                    low++;
                }
                ans=max(ans,high-low+1);
                high++;
            }
        }

        return ans;
        
    }
};
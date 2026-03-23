class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int maxLen=0;
        int maxFreq=0;
        while(j<n){
            mp[s[j]]++;
            maxFreq=max(maxFreq,mp[s[j]]);

            while(j-i+1 - maxFreq > k){
                mp[s[i]]--;
                maxFreq=0;
                for(auto it:mp){
                    maxFreq=max(maxFreq,it.second);
                }
                i++;
            }

            if(j-i+1 - maxFreq <= k){
                maxLen=max(maxLen,j-i+1);
            }
            j++;
        }
        return maxLen;
        
    }
};
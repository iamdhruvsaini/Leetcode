class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0,j=0,ans=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            
            if(mp.size()==j-i+1){
                // no of unique char are equal to the window size so possible answer
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1){
                // window size is less then 
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;

            }
        }
        return ans;

   
    }
};
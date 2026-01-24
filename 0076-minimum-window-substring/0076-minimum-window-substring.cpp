class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";

        unordered_map<char,int>mp;
        for(auto ch:t)mp[ch]++;
        int i=0,j=0,n=s.size(),count=mp.size();
        int len=INT_MAX, index=-1;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)count--;
            }

            while(count==0){
                if(j-i+1 < len){
                    len=j-i+1;
                    index=i;
                }
                // now remove the ith element
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
 
            j++;
        }

        if(len==INT_MAX)return "";
  
        return s.substr(index,len);
        
        
    }
};
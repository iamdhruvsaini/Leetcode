class Solution {
public:
    string minWindow(string s, string t) {
        int low=0,high=0;
        int minlen=INT_MAX;
        unordered_map<char,int>mp;
        for(char ch:t){
            mp[ch]++;
        }
        int char_count=mp.size(),start=-1;

        while(high<s.size()){
            char ch=s[high];
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
                if(mp[ch]==0){
                    char_count--;
                }
            }
            while(char_count==0){
                if(high-low+1<minlen){
                    minlen=high-low+1;
                    start=low;
                }
                    char leftChar=s[low];
                    if(mp.find(leftChar)!=mp.end()){
                         mp[leftChar]++;
                         if(mp[leftChar]>0){
                            char_count++;
                         }
                    }
                    low++;
                
            }
            high++;
        }

        if(start==-1)return "" ;
        return s.substr(start,minlen);
        
    }
};
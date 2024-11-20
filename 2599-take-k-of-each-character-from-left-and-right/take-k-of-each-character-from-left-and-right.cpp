class Solution {
public:
    int takeCharacters(string s, int k) {
        
        int a=count(s.begin(),s.end(),'a');
        int b=count(s.begin(),s.end(),'b');
        int c=count(s.begin(),s.end(),'c');
        if(a<k || b<k || c<k)return -1;
        unordered_map<char,int>mp;
        
        mp['a']=a;
        mp['b']=b;
        mp['c']=c;

        int l=0,r=0;
        int ans=-1;
        while(r<s.size()){
            mp[s[r]]--;
            while(mp[s[r]]<k && l<=r){
                mp[s[l]]++;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return s.size()-ans;
    }
};
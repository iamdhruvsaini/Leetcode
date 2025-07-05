class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        auto cmp=[&](char a, char b){
            if(mp[a]==mp[b])return a<b;
            return mp[a]>mp[b];
        };

        sort(s.begin(),s.end(),cmp);

        return s;

    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return 0;
        vector<int>temp(26,0);
        for(int i=0;i<s.length();i++){
            int index1=s[i]-'a';
            int index2=t[i]-'a';
            temp[index1]++;
            temp[index2]--;
        }

        for(int i=0;i<26;i++){
            if(temp[i]!=0)return 0;
        }

        return 1;
    }
};
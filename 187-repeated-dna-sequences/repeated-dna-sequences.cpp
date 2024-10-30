class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        string temp="";
        int left=0,right=9;
        for(int i=0;i<10;i++){
            temp+=s[i];
        }
        mp[temp]++;
        while(right<s.size()){
            left++;
            right++;
            temp="";
            for(int i=left;i<=right;i++){
                temp+=s[i];
            }
            mp[temp]++;
        
        }

        for(auto str : mp){
            if(str.second > 1){
                ans.push_back(str.first);
            }
        }
        return ans;

    }
};
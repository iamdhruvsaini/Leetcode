class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());

            if(mp.find(temp)!=mp.end()){
                mp[temp].push_back(strs[i]);
            }
            else{
                vector<string>t;
                mp[temp]=t;
                mp[temp].push_back(strs[i]);

            }
        }

        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
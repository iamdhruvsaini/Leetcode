class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string ans="";
        for (int i=0;i<strs[0].size();i++){
            bool flag=false;
            for(int j=1;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans+=strs[0][i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};
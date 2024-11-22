class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        unordered_map<string,int>mp;
        int row=m.size(),col=m[0].size();
        for(int i=0;i<row;i++){
            string s="";
            string t="";
            for(int j=0;j<col;j++){
                s+=to_string(m[i][j]);
                if(m[i][j]==0){
                    t+='1';
                }
                else{
                    t+='0';
                }
            }
            if(mp.find(t)!=mp.end()){
                mp[t]++;
            }
            else if(mp.find(s)!=mp.end()){
                mp[s]++;
            }
            else{
                mp[t]++;
            }

            

        }   
        int ans=-1;   
        for(auto i :mp){
            ans=max(i.second,ans);
        }  
        return ans;
    }
};
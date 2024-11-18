#define vii vector<vector<int>>
class Solution {
public:
    void solve(int s,int e,int k , vii & ans,vector<int>&temp){
        if(s>e){
            if(temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        solve(s+1,e,k,ans,temp);
        temp.push_back(s);
        solve(s+1,e,k,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vii ans;
        vector<int>temp;
        solve(1,n,k,ans,temp);
        return ans;
        
    }
};
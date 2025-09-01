class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&temp,int k, int n,int sum,int cnt,int i){
      

        if(cnt==k){
            if(sum==n)ans.push_back(temp);
            return;
        }
        if(i>9)return;
        if(sum>n){
            return;
        }


        // take the num
        temp.push_back(i);
        solve(ans,temp,k,n,sum+i,cnt+1,i+1);
        temp.pop_back();

        solve(ans,temp,k,n,sum,cnt,i+1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=1;
        solve(ans,temp,k,n,0,0,i);
        return ans;
    }
};
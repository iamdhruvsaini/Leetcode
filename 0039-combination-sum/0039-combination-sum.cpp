class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>> &ans, vector<int>&temp,int target,int sum,int index){
        if(index>=candidates.size()){
            if(sum==target)ans.push_back(temp);
            return;
        }

        if(sum>target){
            return;
        }

        // take a decision 
        temp.push_back(candidates[index]);
        solve(candidates,ans,temp,target,sum+candidates[index],index);
        temp.pop_back();

        solve(candidates,ans,temp,target,sum,index+1);


    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;

        solve(candidates,ans,temp,target,0,0);

        return ans;
    }
};
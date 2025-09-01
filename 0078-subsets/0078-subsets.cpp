class Solution {
public:
    void solve(vector<vector<int>> & ans,vector<int>&temp,vector<int>&nums,int index ){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }

        // case 1: select the value
        temp.push_back(nums[index]);
        solve(ans,temp,nums,index+1);
        temp.pop_back();

        //case 2: ignore the value

        solve(ans,temp,nums,index+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,nums,0);
        return ans;
    }
};
class Solution {
public:
    void solve(vector<int>&candidates,vector<int>&temp,vector<vector<int>>&container,int target,int sum,int index){
        if(index==candidates.size()){
            if(sum==target)container.push_back(temp);
            return;
        }
        if(sum>target)return;


        // take decison
        //case 1: choose
        temp.push_back(candidates[index]);
        solve(candidates,temp,container,target,sum+candidates[index],index+1);
        temp.pop_back();

        while(index + 1 < candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }

        //case 2: skip
        solve(candidates,temp,container,target,sum,index+1);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>container;
        vector<int>temp;
    
        sort(candidates.begin(),candidates.end());
        solve(candidates,temp,container,target,0,0);
        
        return container;
    }
};
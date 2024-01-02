class Solution {
public:
    bool chk(vector<int>&temp,int t){
        for(int i=0;i<temp.size();i++){
            if(temp[i]==t)return false;
        }
        return true;
    }
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        //unordered_map<int,int>mp;
        int n=nums.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            vector<int>temp;
            //nums[i]*=-1;
            for(int j=0;j<n;j++){
                if(nums[j]<0)continue;
                else if(nums[j]>=0 && chk(temp,nums[j])){
                    temp.push_back(nums[j]);
                    nums[j]*=-1;
                }
            }
            if(temp.size()!=0)
            ans.push_back(temp);
        }
        return ans;
        
        
        
    }
};
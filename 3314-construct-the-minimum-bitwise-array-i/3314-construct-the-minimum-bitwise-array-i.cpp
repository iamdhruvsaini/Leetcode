class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                ans.push_back(-1);
                continue;
            }
            for(int j=0;j<32;j++){
                if((nums[i]&(1<<j))> 0){
                    // then it is set
                    continue;
                }
                // unset bit
                int prev=j-1;
                int x=(nums[i]^(1<<prev));
                ans.push_back(x);
                break;
            }       
            // make prev bit as 0

        }

        return ans;
    }
};
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
                // find the last non set bit
                if((nums[i] & (1<<j))!= 0){
                    continue;
                }
                // this is non set bit 
                // do xor then
                int x=1<<j-1;
                x=x^nums[i];
                ans.push_back(x);
                break;
            }
        }

        return ans;
        
    }
};
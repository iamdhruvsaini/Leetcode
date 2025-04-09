class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;

        int preSum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            if(mp.find(preSum-k)!=mp.end()){
                cnt+=mp[preSum-k];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};
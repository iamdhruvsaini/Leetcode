class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0;
        int ans=INT_MIN;
        int cnt=0;
        while(high<nums.size()){
            if(nums[high]==0)cnt++;
            while(cnt>k){
                if(nums[low]==0)cnt--;
                low++;
            }
            ans=max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};
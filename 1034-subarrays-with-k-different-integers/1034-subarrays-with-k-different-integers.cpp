class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k<=0)return 0;

        int low=0,high=0,ans=0;
        unordered_map<int,int>mp;

        while(high<nums.size()){
            mp[nums[high]]++;
            if(mp.size()<=k){
                ans+=high-low+1;
                high++;
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[low]]--;
                    if(mp[nums[low]]==0){
                        mp.erase(nums[low]);
                    }
                    low++;
                }
                ans += high - low + 1; // You need to add this line
                high++;
              
            }
        }   
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int case1=solve(nums,k);
        int case2=solve(nums,k-1);

        return case1-case2;
    }
};
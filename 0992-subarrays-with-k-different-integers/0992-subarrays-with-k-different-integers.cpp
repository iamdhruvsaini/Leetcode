class Solution {
public:
    int f(vector<int>& nums, int k){
        // we have find the no. of subarrays less then k
        int i=0,j=0;
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) { 
        int ans=f(nums,k)-f(nums,k-1);
        return ans;
    }
};
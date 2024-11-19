#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        ll ans=0;
        int l=0;
        int r=k-1;
        ll sum=0;
       
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }

        if(mp.size()==k)ans=max(ans,sum);
        
        while(r< nums.size()){
            sum-=nums[l];
            mp[nums[l]]--;
            if(mp[nums[l]]<=0){
                mp.erase(nums[l]);
            }
            l++;
            r++;
            if(r>=nums.size())break;
            sum+=nums[r];
            mp[nums[r]]++;
            cout<<mp.size()<<" ";
            if(mp.size()>=k)ans=max(ans,sum);
        }
        return ans;
    }
};
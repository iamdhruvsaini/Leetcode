class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){
        int part=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                part++;
                sum=nums[i];
                if(part > k)return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        // similar to Book Allocation
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);

        int ans=-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(isPossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
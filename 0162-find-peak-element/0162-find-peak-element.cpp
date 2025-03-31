class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // similar to finding the peak element
        int n=nums.size();
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;

        int s=1,e=n-2;

        while(s<=e){
            int mid=s+(e-s)/2;            

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                //it is on increasing ramp
                s=mid+1;
            }
            else{
                //it is on decreasing ramp or at local minima point 
                // also moving anywhere from local minima would lead to answer 
                // however here we have to consider the decreasing ramp condition also
                // so lets move to 
                e=mid-1; 
            }
        }
        return -1;
    }
};
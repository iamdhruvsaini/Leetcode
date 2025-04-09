class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int j=n-2;j>=0;j--){
            if(nums[j]<nums[j+1]){
                ind=j;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // find mini maximum element
        int mini=-1;
        for(int j=n-1;j>ind;j--){
            if(nums[j]>nums[ind]){
                mini=j;
                break;
            }
        }
        swap(nums[ind],nums[mini]);

        reverse(nums.begin()+ind+1,nums.end());


    }
};
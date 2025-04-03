class Solution {
public:
    bool findSum(vector<int>& nums, int threshold,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum>threshold)return 0;
            sum+=nums[i]/divisor;
            //handling of rounding case
            if(nums[i]%divisor != 0){
                sum+=1;
            }
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int s=1,e=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(findSum(nums,threshold,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};
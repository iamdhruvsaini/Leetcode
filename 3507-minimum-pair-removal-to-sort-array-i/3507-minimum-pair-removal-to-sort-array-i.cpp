class Solution {
public:
    int getMinSum(vector<int>& nums){
        int sum=INT_MAX, index=0;
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i]+nums[i+1])<sum){
                sum=nums[i]+nums[i+1];
                index=i;
            }
        }
        nums[index]=sum;
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {

        int partitions=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int index=getMinSum(nums);
            nums.erase(nums.begin()+index+1);
            partitions++;
        }

        return partitions;
    }
};